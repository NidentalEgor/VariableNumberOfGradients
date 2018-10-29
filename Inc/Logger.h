//
// Created by egor on 30.10.18.
//

#ifndef VARIABLENUMBEROFGRADIENTS_LOGGER_H
#define VARIABLENUMBEROFGRADIENTS_LOGGER_H

#include <string>
#include <iostream>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

class Traceble {
public:
    virtual ~Traceble(){}

    void Log( const char* file_name,
              const int line,
              const char* message )
    {
        std::cout << "file name: " << file_name << " line: " << line << " || " << message << std::endl;
    }
    void Log( const char* file_name,
              const int line,
              const std::string& message )
    {
        std::cout << "file name: " << file_name << " line: " << line << " || " << message << std::endl;
    }

    void Log( const std::string& message )
    {
        std::cout << "Logger || " << message << std::endl;
    }
};


#endif //VARIABLENUMBEROFGRADIENTS_LOGGER_H
