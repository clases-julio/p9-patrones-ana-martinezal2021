#include "StringException.h"

StringException::StringException()
  :std::runtime_error ("you've entered a character when only integers are allowed"){};
