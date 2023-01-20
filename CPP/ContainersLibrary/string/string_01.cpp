/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
  std::vector<std::string> myvector = {
      "alpha",
      "beta",
      "gamma"};

  std::cout << myvector.at(0).at(0) << std::endl; // myVector[0][0]
  // or
  std::cout << myvector[0][0] << std::endl; // myVector[0][0]

  // assign a new value to the first element of the first string
  myvector.at(0).at(0) = 'A';
  // or
  myvector[0][0] = 'A';

  std::cout << myvector[0] << std::endl; // myVector[0]

  return 0;
}