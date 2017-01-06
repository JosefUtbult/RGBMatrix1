#ifndef LEDWRITER_H
#define LEDWRITER_H

#include "Const.h"

class LedWriter
{
public:
  LedWriter(int _currentMatrix[MATRIXSIZE * MATRIXSIZE]);
  void writeLed();
private:
  int currentMatrix[MATRIXSIZE * MATRIXSIZE];

};

#endif LEDWRITER_H
