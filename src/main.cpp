#include <iostream>
#include "logger.h" //allows the main.cpp to use logger
#include "recovery.h"
#include "cache.h"
using namespace std;

int main() {
    cout << "System Started" << endl;
    //Transaction-1 Successful
    writeLog("TXN 1 START WRITE file1 data123");//sends message to logger
    writeLog("TXN 1 COMMIT");
    //Transaction-2 Crash Simulation
    writeLog("TXN 2 START WRITE file2 data456");
    cout << "Simulating crash..." << endl;
    cout << "\n--- Cache Simulation ---\n";

    // Store data in cache
    putCache("file1", "data123");
    putCache("file2", "data456");

    // Retrieve data
    getCache("file1");   // should be HIT
    getCache("file3");   // should be MISS

    // Show all cache
    showCache();
    cout << "\n--- Recovery Phase ---\n";
    recoverSystem();
    return 0;
}