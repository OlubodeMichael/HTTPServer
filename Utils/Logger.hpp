//
//  Logger.hpp
//  HTTPServer
//  Header for logging functionality
//  Created by Michael Olubode on 2/16/25.
//

/*
 (Logging Utility Header)
 📌 Purpose: Provides a simple logging mechanism.

 🔹 Functions to Implement:

 void logInfo(std::string message); → Logs general information.
 void logError(std::string message); → Logs error messages.

*/

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger {
public:
    static void logInfo(const std::string& message);
    static void logError(const std::string& message);
};

#endif // LOGGER_HPP
