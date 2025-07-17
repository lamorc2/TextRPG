#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>

class Logger {
public:
    static void Init(bool enableConsole = true, const std::string& logFile = "") {
        consoleEnabled = enableConsole;
        if (!logFile.empty()) {
            fileStream.open(logFile, std::ios::out | std::ios::app);
            fileEnabled = fileStream.is_open();
        }
    }

    static void Log(const std::string& message) {
        if (consoleEnabled) {
            std::cout << "[DEBUG] " << message << std::endl;
        }
        if (fileEnabled) {
            fileStream << "[DEBUG] " << message << std::endl;
        }
    }

    static void Shutdown() {
        if (fileEnabled) {
            fileStream.close();
        }
    }

private:
    static inline bool consoleEnabled = true;
    static inline bool fileEnabled = false;
    static inline std::ofstream fileStream;
};

#endif