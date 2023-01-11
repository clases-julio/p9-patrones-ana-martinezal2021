/**
* @file StringException.h
* @brief defines the string exception class with its constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/
#include <stdexcept> // contains runtime_error

class StringException : public std::runtime_error {
public:
  StringException();
};
