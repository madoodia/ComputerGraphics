/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <vector>
#include <string>


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