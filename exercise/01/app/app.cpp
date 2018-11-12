#include "pch.h"
#include <iostream>
#include "../lib/public.h"
#include "../dll2/public.h"
#include <functional>
#include <windows.h>
#include <string>

int main()
{
  auto dll = LoadLibrary(TEXT("dynamic_library.dll"));
  auto proc_address = GetProcAddress(dll, "get_value");
  auto func = std::function<double(int)>(reinterpret_cast<double (__stdcall *)(int)>(proc_address));
  auto value = (func) (1);

  std::cout << "Static library " << static_lib::get_value(1) << '\n';
  std::cout << "DLL " << value << '\n';
  std::cout << "DLL with implib " << get_value(1) << '\n';

  FreeLibrary(dll);
}
