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
  std::vector<std::string> myVector = {};

  myVector.push_back("alpha");
  myVector.push_back("beta");
  myVector.push_back("gamma");
  myVector.push_back("delta");
  myVector.push_back("epsilon");
  myVector.push_back("zeta");
  myVector.push_back("eta");
  myVector.push_back("theta");
  myVector.push_back("iota");
  myVector.push_back("kappa");
  std::cout << myVector.size() << std::endl;
  std::cout << myVector.capacity() << std::endl;

  std::cout << myVector.at(0).at(0) << std::endl; // myVector[0][0]
  // or
  std::cout << myVector[0][0] << std::endl; // myVector[0][0]

  // assign a new value to the first element of the first string
  myVector.at(0).at(0) = 'A';
  // or
  myVector[0][0] = 'A';

  std::cout << myVector[2][3] << std::endl;

  std::cout << myVector[0] << std::endl; // myVector[0]
  std::cout << myVector[1] << std::endl; // myVector[1]
  std::cout << myVector[2] << std::endl; // myVector[2]
  std::cout << myVector[3] << std::endl; // myVector[3]
  std::cout << myVector[4] << std::endl; // myVector[4]
  std::cout << myVector[5] << std::endl; // myVector[5]
  // std::cout << myVector[6] << std::endl; // myVector[6]

  // create a vector of strings of pilot alphabet
  std::vector<std::string> pilotAlphabet = {
      "alpha",
      "bravo",
      "charlie",
      "delta",
      "echo",
      "foxtrot",
      "golf",
      "hotel",
      "india",
      "juliet",
      "kilo",
      "lima",
      "mike",
      "november",
      "oscar",
      "papa",
      "quebec",
      "romeo",
      "sierra",
      "tango",
      "uniform",
      "victor",
      "whiskey",
      "x-ray",
      "yankee",
      "zulu"};
  std::cout << pilotAlphabet.size() << std::endl;
  std::cout << pilotAlphabet.capacity() << std::endl;

  // create a vector of strings of greek numbers name
  std::vector<std::string> greekNumbers = {
      "alpha",
      "beta",
      "gamma",
      "delta",
      "epsilon",
      "zeta",
      "eta",
      "theta",
      "iota",
      "kappa",
      "lambda",
      "mu",
      "nu",
      "xi",
      "omicron",
      "pi",
      "rho",
      "sigma",
      "tau",
      "upsilon",
      "phi",
      "chi",
      "psi",
      "omega"};
  std::cout << greekNumbers.size() << std::endl;
  std::cout << greekNumbers.capacity() << std::endl;

  // create a vector of strings of 10 randome names
  std::vector<std::string> randomNames = {
      "John",
      "Paul",
      "George",
      "Ringo",
      "Pete",
      "Stuart",
      "Mick",
      "Keith",
      "Ronnie",
      "Charlie"};

  // create a map of vectors of strings
  std::map<std::string, std::vector<std::string>> myMap = {
      {"pilotAlphabet", pilotAlphabet},
      {"greekNumbers", greekNumbers}};

  myMap["pilotAlphabet"].push_back("alpha");

  // create a multimap of vectors of strings
  std::multimap<std::string, std::vector<std::string>> myMultiMap = {
      {"pilotAlphabet", pilotAlphabet},
      {"greekNumbers", greekNumbers}};

  myMultiMap.insert(std::pair<std::string, std::vector<std::string>>("pilotAlphabet", pilotAlphabet));

  return 0;
}