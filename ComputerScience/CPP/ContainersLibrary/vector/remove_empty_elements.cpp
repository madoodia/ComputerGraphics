/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <sstream>
#include <string>
#include <vector>

// or
int main()
{
  // method 1
  {
    std::vector<std::string> vec = {"hello", "", "world", "", "", "c++"};
    vec.erase(std::remove(vec.begin(), vec.end(), ""), vec.end());
  }

  // method 2
  {
    std::vector<std::string> vec = {"hello", "", "world", "", "", "c++"};
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](const std::string& s)
                             { return s.empty(); }),
              vec.end());
  }

  // method 3
  {
    std::vector<std::string> vec = {"hello", "", "world", "", "", "c++"};
    for (auto it = vec.begin(); it != vec.end();)
    {
      if (it->empty())
      {
        it = vec.erase(it);
      }
      else
      {
        ++it;
      }
    }
  }
}