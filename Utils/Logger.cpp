//
//  Logger.cpp
//  HTTPServer
//  Implementation of logging
//  Created by Michael Olubode on 2/16/25.
//

/*
 (Logging Implementation)
 📌 Purpose: Implements the logging functions.

 🔹 Implementation Steps:

 Open an output stream (std::ofstream) to write logs.
 Format logs with timestamps.
 Append logs to a file (server.log).
*/

#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

void Logger::logInfo(const string& message) {
    ofstream logFile("server.log", std::ios::app);
    time_t now = time(nullptr);
    logFile << "[INFO] " << std::ctime(&now) << " - " << message << endl;
    logFile.close();
}

void Logger::logError(const std::string& message) {
    ofstream logFile("server.log", std::ios::app);
    time_t now = time(nullptr);
    logFile << "[ERROR] " << std::ctime(&now) << " - " << message << endl;
    logFile.close();
}
