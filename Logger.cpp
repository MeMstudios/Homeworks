//
// Created by Michael on 9/14/2016.
//


#include "Logger.h"
namespace std {

        Logger::Logger();
        Logger::Logger(Logger &const copy);
        Logger& Logger::operator=(Logger &const copy);

        static Logger* Logger::getInstance() {
            static Logger instance;
            return &instance;
        }
        void Logger::log(const string output) {
            cout << output << endl;
        }
    }

