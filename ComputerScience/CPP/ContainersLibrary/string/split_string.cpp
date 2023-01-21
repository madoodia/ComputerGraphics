/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <sstream>
#include <string>
#include <vector>
#include <ranges>
#include <format>

std::vector<std::string> split_string(std::string_view str, std::string_view delimiter)
{
  std::vector<std::string> words;
  std::string::size_type start = 0;
  std::string::size_type end = str.find(delimiter);
  while (end != std::string::npos)
  {
    words.emplace_back(str.substr(start, end - start));
    start = end + delimiter.length();
    end = str.find(delimiter, start);
  }
  words.emplace_back(str.substr(start, end));
  return words;
}

int main()
{
  // method 1
  {
    std::string str = "hello world from madoodia ";
    std::stringstream ss(str);
    std::vector<std::string> words;
    std::string word;
    while (ss >> word)
    {
      words.push_back(word);
    }
  }

  // method 2
  {

    std::string str = "hello world from madoodia ";
    std::string delimiter = " ";
    std::vector<std::string> words;
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos)
    {
      token = str.substr(0, pos);
      words.push_back(token);
      str.erase(0, pos + delimiter.length());
    }
    words.push_back(str);
  }

  // method 3
  {
    std::string str = "hello world from madoodia ";
    std::string delimiter = " ";
    std::vector<std::string> words;
    size_t pos = 0;
    while ((pos = str.find_first_of(delimiter)) != std::string::npos)
    {
      words.push_back(str.substr(0, pos));
      str = str.substr(pos + 1);
    }
    words.push_back(str);
  }

  // method 4 C++20
  {
    std::string str = "hello world from madoodia ";
    auto words = split_string(str, " ");
  }

  // method 5 C++23
  {
    std::string str = "hello world from madoodia ";
    std::vector<std::string> words;
    for (std::string_view word : str | std::views::split(' '))
    {
      words.push_back(std::string(word));
    }
  }
}