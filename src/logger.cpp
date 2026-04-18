#include "logger.h"
#include <fstream> // allows to work with files
#include <iostream>
using namespace std;
void writeLog(string message)
{
    ofstream logFile("../data/logs.txt", ios::app);//open in append mode
    if(logFile.is_open())
    {
        logFile << message << endl;//writes th message into the file
        logFile.close();//closes the file
    }
    else{
        cout<< "Failed to open log file" << endl;
    }
}