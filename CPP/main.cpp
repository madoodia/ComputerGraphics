/*
# -------------------- #
# (C)2022 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <vector>
#include <string>

#include <Windows.h>

int main()
{
  std::cout << "Hello VSCode!" << std::endl;

  std::vector<std::string> cities = {"NY", "LA"};
  cities.push_back("VAN");

  for (const std::string city : cities)
  {
    std::cout << "city: " << city << std::endl;
  }

  return 0;
}