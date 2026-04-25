#include "logger.h"
#include <fstream> // allows to work with files
#include <iostream>
#include <ctime>
using namespace std;
void writeLog(string message)
{
    ofstream logFile("C:\\Users\\Varnika Sharma\\Desktop\\File_Recovery_Tool\\File-System-Recovery-and-Optimization-Tool\\data\\logs.txt", ios::app);
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