/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

// implement a hash table data structure
// implement a hash function
int hashFunction(std::string s)
{
  int key = 0;
  for (int i = 0; i < s.size(); i++)
  {
    key += int(s[i]);
    // std::cout << int(s[i]) << ":" << s[i] << " + ";
  }
  // std::cout << "\b\b>> " << key << " > " << key % s.size() << std::endl;
  return key % s.size();
}

int main()
{
  std::map<int, std::vector<std::string>> hashTable;

  std::vector<std::string> vec = {"ab", "cde", "fg", "hijk", "lmn", "opq", "rst", "uvwxyz", "madoodia"};

  for (int i = 0; i < vec.size(); i++)
  {
    int key = hashFunction(vec[i]);
    hashTable[key].push_back(vec[i]);
  }

  for (auto i : hashTable)
  {
    std::cout << i.first << ": ";
    for (auto j : i.second)
    {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}