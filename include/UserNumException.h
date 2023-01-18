/**
* @file UserNumException.h
* @brief defines the user number exception class with its constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/
#include <stdexcept> // contains runtime_error

class UserNumException : public std::runtime_error {
public:
  UserNumException();
};
