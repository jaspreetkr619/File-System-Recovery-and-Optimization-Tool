#include <iostream>
#include <string>
#include "logger.h"
#include "recovery.h"
#include "cache.h"

using namespace std;

int txnCounter = 1;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "No command provided.\n";
        return 1;
    }

    string command = argv[1];

    if (command == "transaction" && argc == 4) {
        string file = argv[2];
        string data = argv[3];

        int txnId = txnCounter++;

        string startLog = "TXN " + to_string(txnId) + " | START | WRITE " + file + " " + data;
        writeLog(startLog);

        putCache(file, data);

        string commitLog = "TXN " + to_string(txnId) + " | COMMIT";
        writeLog(commitLog);

        cout << "[SUCCESS] Transaction completed.\n";
    }

    else if (command == "crash" && argc == 4) {
        string file = argv[2];
        string data = argv[3];

        int txnId = txnCounter++;

        string startLog = "TXN " + to_string(txnId) + " | START | WRITE " + file + " " + data;
        writeLog(startLog);

        cout << "[WARNING] Crash simulated. No commit.\n";
    }

    else if (command == "recovery") {
        recoverSystem();
    }

    else if (command == "cache") {
        showCache();
    }

    else if (command == "clear") {
        ofstream logFile("../data/logs.txt", ios::trunc);
        logFile.close();
        cout << "[INFO] Logs cleared.\n";
    }

    else {
        cout << "Invalid command.\n";
    }

    return 0;
}