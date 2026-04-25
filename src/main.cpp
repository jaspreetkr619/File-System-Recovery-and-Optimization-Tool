#include <iostream>
#include "logger.h"
#include "recovery.h"
#include "cache.h"
int txnCounter = 1;
using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "\n=================================\n";
        cout << "     FILE SYSTEM SIMULATOR\n";
        cout << "=================================\n";
        cout << "1. Perform Transaction\n";
        cout << "2. Simulate Crash\n";
        cout << "3. Run Recovery\n";
        cout << "4. Show Cache\n";
        cout << "5. Exit\n";
        cout << "---------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            string file, data;

            cout << "Enter file name: ";
            cin >> file;

            cout << "Enter data: ";
            cin >> data;

            int txnId = txnCounter++;

            string startLog = "TXN " + to_string(txnId) + " START WRITE " + file + " " + data;
            writeLog(startLog);

            putCache(file, data);

            string commitLog = "TXN " + to_string(txnId) + " | COMMIT";
            writeLog(commitLog);

           cout << "[SUCCESS] Transaction committed.\n";
        }
        if (choice == 2) {
            string file, data;

            cout << "Enter file name: ";
            cin >> file;

            cout << "Enter data: ";
            cin >> data;

           int txnId = txnCounter++;

            string startLog = "TXN " + to_string(txnId) + " | START | WRITE " + file + " " + data;
            writeLog(startLog);

            cout << "[WARNING] Crash simulated. Transaction not committed.\n";
        }
        if (choice == 3) {
            cout << "\n--- Running Recovery ---\n";
            recoverSystem();
        }
        if (choice == 4) {
            showCache();
        }
        if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }
    }

    return 0;
}