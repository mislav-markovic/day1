#include "stdafx.h"


extern "C" _declspec(dllexport) double get_value(int input)
{
  return input * 2.5;
}
