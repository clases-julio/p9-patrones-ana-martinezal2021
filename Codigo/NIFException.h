/**
* @file NIFException.h
* @brief defines the NIF exception class with its constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/
#include <stdexcept> // contains runtime_error

class NIFException : public std::runtime_error {
public:
  NIFException();
};
