#include <iostream>
#include "logger.h" //allows the main.cpp to use logger
#include "recovery.h"
using namespace std;

int main() {
    cout << "System Started" << endl;
    //Transaction-1 Successful
    writeLog("TXN 1 START WRITE file1 data123");//sends message to logger
    writeLog("TXN 1 COMMIT");
    //Transaction-2 Crash Simulation
    writeLog("TXN 2 START WRITE file2 data456");
    cout << "Simulating crash..." << endl;
    cout << "\n--- Recovery Phase ---\n";
    recoverSystem();
    return 0;
}