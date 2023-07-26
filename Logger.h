#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream> // For file I/O
#include <string>
using namespace std;
class Logger {
public:
    // Function to log a message to the log file
    static void log(const string& message);

    // Function to log an error to the error log file
    static void error(const string& message);
};

#endif // LOGGER_H

