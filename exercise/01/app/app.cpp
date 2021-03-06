#include "pch.h"
#include <iostream>
#include "../lib/public.h"
#include "../dll2/public.h"
#include <functional>
#include <Windows.h>
#include <string>

int main()
{
  const auto dll = LoadLibraryA("dynamic_library.dll");
  const auto proc_address = GetProcAddress(dll, "get_value");
  const auto func = std::function<double(int)>(reinterpret_cast<double(*)(int)>(proc_address));

  std::cout << "Static library " << static_lib::get_value(1) << '\n';
  std::cout << "DLL " << func(1) << '\n';
  std::cout << "DLL with implib " << get_value(1) << '\n';

  FreeLibrary(dll);
}
