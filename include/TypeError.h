/**
* @file TypeError.h
* @brief defines the user type exception class with its constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/
#include <stdexcept> // contains runtime_error

class TypeError : public std::runtime_error {
public:
  TypeError();
};
