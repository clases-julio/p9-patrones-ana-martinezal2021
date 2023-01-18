#include "../include/NIFException.h"

NIFException::NIFException()
  :std::runtime_error ("the number of digits for password must be 8."){};
