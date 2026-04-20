#include <iostream>
#include "logger.h"
#include "recovery.h"
#include "cache.h"

using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "\n===== File System Simulator =====\n";
        cout << "1. Perform Transaction\n";
        cout << "2. Simulate Crash\n";
        cout << "3. Run Recovery\n";
        cout << "4. Show Cache\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            string file, data;

            cout << "Enter file name: ";
            cin >> file;

            cout << "Enter data: ";
            cin >> data;

            string startLog = "TXN 1 START WRITE " + file + " " + data;
            writeLog(startLog);

            putCache(file, data);

            string commitLog = "TXN 1 COMMIT";
            writeLog(commitLog);

            cout << "Transaction completed successfully.\n";
        }
        if (choice == 2) {
            string file, data;

            cout << "Enter file name: ";
            cin >> file;

            cout << "Enter data: ";
            cin >> data;

            string startLog = "TXN 2 START WRITE " + file + " " + data;
            writeLog(startLog);

            cout << "Simulating crash... (no commit)\n";
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