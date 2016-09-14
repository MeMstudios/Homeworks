//
// Created by Michael on 9/14/2016.
//

#ifndef SINGLETON_LOGGER_H
#define SINGLETON_LOGGER_H

#include <string>
#include <iostream>

namespace std {
    class Logger { //a singleton class
    private:
        Logger();
        Logger(Logger &const copy);
        Logger & operator=(Logger &const copy);
    public:
        static Logger* getInstance();
        void log(const string output);
    };
}
#endif //SINGLETON_LOGGER_H
