#include <iostream>
#include "logger.h" //allows the main.cpp to use logger
using namespace std;

int main() {
    cout << "System Started" << endl;
    writeLog("TXN 1 START WRITE file1 data123");//sends message to logger
    writeLog("TXN 1 COMMIT");
    return 0;
}