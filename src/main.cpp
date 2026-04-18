#include <iostream>
#include "logger.h" //allows the main.cpp to use logger
using namespace std;

int main() {
    cout << "System Started" << endl;
    writeLog("SYSTEM STARTED");//sends message to logger
    return 0;
}