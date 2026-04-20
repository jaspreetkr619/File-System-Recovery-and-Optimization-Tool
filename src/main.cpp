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

        if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }
    }

    return 0;
}