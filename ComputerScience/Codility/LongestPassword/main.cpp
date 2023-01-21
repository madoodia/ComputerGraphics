/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

/*
You would like to set a password for a bank account. However, there are three restrictions on the format of the password:

it has to contain only alphanumerical characters (a−z, A−Z, 0−9);
there should be an even number of letters;
there should be an odd number of digits.
You are given a string S consisting of N characters. String S can be divided into words by splitting it at, and removing, the spaces. The goal is to choose the longest word that is a valid password. You can assume that if there are K spaces in string S then there are exactly K + 1 words.

For example, given "test 5 a0A pass007 ?xy1", there are five words and three of them are valid passwords: "5", "a0A" and "pass007". Thus the longest password is "pass007" and its length is 7. Note that neither "test" nor "?xy1" is a valid password, because "?" is not an alphanumerical character and "test" contains an even number of digits (zero).

Write a function:

  int solution(string &S);

that, given a non-empty string S consisting of N characters, returns the length of the longest word from the string that is a valid password. If there is no such word, your function should return −1.

For example, given S = "test 5 a0A pass007 ?xy1", your function should return 7, as explained above.

Assume that:
  - N is an integer within the range [1..200];
  - string S consists only of printable ASCII characters and spaces.

In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/

#include <iostream>
#include <string>
#include <cassert>

int isValidPassword(std::string word)
{
  int letterCount = 0;
  int digitCount = 0;
  for (unsigned int i = 0; i < word.size(); i++)
  {
    if (isalnum(word[i]))
    {
      if (isalpha(word[i]))
      {
        letterCount++;
      }
      else if (isdigit(word[i]))
      {
        digitCount++;
      }
    }
    else
    {
      return -1;
    }
  }
  if (letterCount % 2 == 0 && digitCount % 2 != 0)
  {
    return word.size();
  }
  return -1;
}

int solution(std::string& S)
{
  int maxLength = -1;
  std::string word = "";
  for (unsigned int i = 0; i < S.size(); i++) // S.size() == S.length()
  {
    if (S[i] != ' ')
    {
      word += S[i];
    }
    else
    {
      int validLength = isValidPassword(word);
      if (validLength > maxLength)
      {
        maxLength = validLength;
      }
      word = "";
    }
  }
  int validLength = isValidPassword(word);
  if (validLength > maxLength)
  {
    maxLength = validLength;
  }
  return maxLength;
}

void test()
{
  std::string S = " test 5 a0A pass007 ?xy1";
  assert(solution(S) == 7);
  S = "test 5 a0A pass007";
  assert(solution(S) == 7);
  S = "test5a0Apass007";
  assert(solution(S) == 15);
  S = "test test1";
  assert(solution(S) == 5);
  S = "test 5 a0A pass007 ?xy1";
  assert(solution(S) == 7);
  S = "";
  assert(solution(S) == -1);
  S = "abc";
  assert(solution(S) == -1);
  S = "123";
  assert(solution(S) == 3);
  S = "a1b2c3";
  assert(solution(S) == -1);
  S = "a1b2c3d 4e5f 6g7h8 kjhHDF6734KJHFDF ?i9j0 kjh12oiuSDiu23oi2";
  assert(solution(S) == 17);
}

int main()
{
  test();

  // std::string S = "test 5 a0A pass007 ?xy1";
  // std::cout << solution(S) << std::endl;
  std::cout << "All test cases pass" << std::endl;
  return 0;
}