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

    cout << "Analyzing logs..." << endl;

    while (getline(logFile, line)) {
        cout << line << endl;

        // Extract transaction ID
        if (line.find("TXN") != string::npos) {
            int txnId = line[4] - '0'; // simple extraction (assumes single digit)

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
            cout << "Transaction " << txn << " is incomplete → rolling back..." << endl;
            // Simulate rollback
            cout << "Rollback of TXN " << txn << " completed." << endl;
}
    }
}