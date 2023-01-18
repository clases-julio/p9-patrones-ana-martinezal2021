#include "../include/UserNumException.h"

UserNumException::UserNumException()
  :std::runtime_error ("the number of digits in user must be between 1 and 5."){};
