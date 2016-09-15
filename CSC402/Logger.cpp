//
// Created by Michael on 9/14/2016.
//


#include "Logger.h"


Logger::Logger(){};
Logger::Logger(Logger const &copy){};
Logger& Logger::operator=(Logger const &copy){};
Logger & Logger::getInstance() {
    static Logger instance;
    return instance;
}
void Logger::log(const std::string output) {
    std::cout << output << std::endl;
}


