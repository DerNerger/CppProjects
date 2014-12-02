#ifndef UDE_H
#define UDE_H

#include <stdexcept>
using namespace std;

class UngueltigesDatumException : public runtime_error{
  public:
    UngueltigesDatumException(const char* str) : runtime_error(str) {}
    UngueltigesDatumException() : runtime_error("Datum ist ungueltig") {}
};

#endif
