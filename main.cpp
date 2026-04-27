#include <iostream>
#include <string>
#include <fstream>
#include "src/logger.h"
#include "src/recovery.h"
#include "src/cache.h"
#include "core/Directory.h"
#include "core/StorageManager.h"
#include "core/File.h"
using namespace std;

int txnCounter = 1;

int main(int argc, char* argv[]) {
    // Initialize system (Person-1 setup)
    StorageManager storage(10);
    Directory root("root");

    if (argc < 2) {
        cout << "No command provided.\n";
        return 1;
    }

    string command = argv[1];

    // ================= TRANSACTION =================
if (command == "transaction" && argc == 4) {
    string fileName = argv[2];
    string data = argv[3];

    int txnId = txnCounter++;

    // Log START
    string startLog = "TXN " + to_string(txnId) + " | START | WRITE " + fileName + " " + data;
    writeLog(startLog);

    // CACHE
    string cached = getFromCache(fileName);

    if (cached != "") {
        cout << "[CACHE HIT] " << fileName << endl;
    } else {
        cout << "[CACHE MISS] " << fileName << endl;
        putCache(fileName, data);
    }

    // REAL FILE WRITE
    string filePath = "data/files/" + fileName;
    ofstream outFile(filePath);
    outFile << data;
    outFile.close();

    // Log COMMIT
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

    else if (command == "search" && argc == 3) {
        string fileName = argv[2];
        string filePath = "data/files/" + fileName;

        ifstream file(filePath);

        if (file) {
            cout << "[FOUND] " << fileName << endl;
            file.close();
        } else {
            cout << "[NOT FOUND] " << fileName << endl;
        }
    }

    else if (command == "list") {
        cout << "\nFiles in system:\n";
        system("dir data\\files");   // Windows
    }

    else if (command == "recovery") {
        recoverSystem();
    }

    else if (command == "cache") {
        showCache();
    }

   else if (command == "clear") {

    // Clear logs
    ofstream logFile("data/logs.txt", ios::trunc);
    logFile.close();

    // Clear cache
    ofstream cacheFile("data/cache.txt", ios::trunc);
    cacheFile.close();

    ofstream statsFile("data/cache_stats.txt", ios::trunc);
    statsFile << "0 0";
    statsFile.close();

    // 🔥 DELETE REAL FILES
    system("del /Q data\\files\\*");   // Windows

    cout << "[INFO] Logs, Cache, and Files cleared.\n";
}

    else {
        cout << "Invalid command.\n";
    }

    return 0;
}