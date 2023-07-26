#include "Logger.h"
using namespace std;

void Logger::log(const string& message) {
    ofstream logFile("log.txt", ios::app); // Open the log file in append mode
    if (logFile.is_open()) {
        logFile << "[LOG]: " << message << endl;
        logFile.close();
    }
}

void Logger::error(const string& message) {
    ofstream errorFile("error.log", ios::app); // Open the error log file in append mode
    if (errorFile.is_open()) {
        errorFile << "[ERROR]: " << message << endl;
        errorFile.close();
    }
}
