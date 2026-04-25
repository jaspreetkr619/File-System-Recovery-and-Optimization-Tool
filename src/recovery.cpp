#include "recovery.h"
#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

void recoverSystem() {
    ifstream logFile("../data/logs.txt");

    if (!logFile.is_open()) {
        cout << "Failed to open log file" << endl;
        return;
    }

    set<int> activeTransactions;
    string line;

    cout << "\n[INFO] Analyzing logs...\n" << endl;

    while (getline(logFile, line)) {
        cout << line << endl;

        // Extract transaction ID
        if (line.find("TXN") != string::npos) {
            int txnId = -1;

            // Extract number after "TXN "
            size_t pos = line.find("TXN ");
            if (pos != string::npos) {
                size_t start = pos + 4;
                size_t end = line.find(" ", start);

                string idStr = line.substr(start, end - start);
                txnId = stoi(idStr);
            }

            if (line.find("START") != string::npos) {
                activeTransactions.insert(txnId);
            }

            if (line.find("COMMIT") != string::npos) {
                activeTransactions.erase(txnId);
            }
        }
    }

    logFile.close();

    cout << "\n--- Recovery Result ---\n";

    if (activeTransactions.empty()) {
        cout << "All transactions completed successfully" << endl;
    } else {
        for (int txn : activeTransactions) {
            cout << "Transaction " << txn << " is incomplete - rolling back..." << endl; //fix
            // Simulate rollback
            cout << "Rollback of TXN " << txn << " completed." << endl;
}
    }
}