#include "logger.h"
#include <fstream> // allows to work with files
#include <iostream>
#include <ctime>
using namespace std;
void writeLog(string message)
{
    ofstream logFile("../data/logs.txt", ios::app);//open in append mode
    if(logFile.is_open())
    {
        time_t now = time(0);
        char* dt = ctime(&now);

        // remove newline from ctime
        string timeStr(dt);
        timeStr.pop_back();

        logFile << "[" << timeStr << "] | " << message << endl;
        logFile.close();//closes the file
    }
    else{
        cout<< "Failed to open log file" << endl;
    }
}