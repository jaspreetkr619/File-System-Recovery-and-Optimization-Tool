#include <iostream>
#include <string>
#include <fstream>

#include "logger.h"
#include "recovery.h"
#include "cache.h"

// Person 1 modules
#include "core/File.h"
#include "core/Directory.h"
#include "core/StorageManager.h"

using namespace std;

int txnCounter = 1;

int main(int argc, char* argv[]) {

    // Initialize Disk System (Person 1)
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

        // CACHE (simple integration)
        string cached = getFromCache(fileName);

if (cached != "") {
    cout << "[CACHE HIT] " << fileName << endl;
} else {
    cout << "[CACHE MISS] " << fileName << endl;
    putCache(fileName, data);
}

        // DISK WRITE (Person 1)
        File file(fileName, data.length());
        file.write(data);
        root.addFile(file);
        storage.allocateBlocks(1);

        // Log COMMIT
        string commitLog = "TXN " + to_string(txnId) + " | COMMIT";
        writeLog(commitLog);

        cout << "[SUCCESS] Transaction completed.\n";
    }

    // ================= CRASH =================
    else if (command == "crash" && argc == 4) {
        string fileName = argv[2];
        string data = argv[3];

        int txnId = txnCounter++;

        string startLog = "TXN " + to_string(txnId) + " | START | WRITE " + fileName + " " + data;
        writeLog(startLog);

        cout << "[WARNING] Crash simulated. No commit.\n";
    }

    // ================= RECOVERY =================
    else if (command == "recovery") {
        recoverSystem();
    }

    // ================= CACHE =================
    else if (command == "cache") {
        showCache();
    }

    // ================= CLEAR LOGS =================
    else if (command == "clear") {
        ofstream logFile("C:\\Users\\Varnika Sharma\\Desktop\\File_Recovery_Tool\\File-System-Recovery-and-Optimization-Tool\\data\\logs.txt", ios::trunc);
        // also clear cache
ofstream cacheFile("C:\\Users\\Varnika Sharma\\Desktop\\File_Recovery_Tool\\File-System-Recovery-and-Optimization-Tool\\data\\cache.txt", ios::trunc);
ofstream statsFile("C:\\Users\\Varnika Sharma\\Desktop\\File_Recovery_Tool\\File-System-Recovery-and-Optimization-Tool\\data\\cache_stats.txt", ios::trunc);

        if (!logFile) {
            cout << "Error: Could not open log file.\n";
            return 1;
        }

        logFile.close();
        cout << "[INFO] Logs cleared.\n";
    }

    else {
        cout << "Invalid command.\n";
    }

    return 0;
}