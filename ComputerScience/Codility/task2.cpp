#include <algorithm>
#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool isNumber(string word)
{
  for (unsigned int i = 0; i < word.size(); ++i)
  {
    if (word[i] == '-' && word.size() != 1)
      continue;
    if (!isdigit(word[i]))
      return false;
  }
  return true;
}

int solution(string& S)
{
  stack<string> myStack;

  if (S.size() > 2000)
    return -1;

  vector<string> words{};
  string word = "";

  for (unsigned int i = 0; i < S.size(); ++i)
  {
    if (S[i] != ' ')
    {
      word += S[i];
      continue;
    }
    words.push_back(word);
    word = "";
  }
  if (word != "")
    words.push_back(word);

  for (string word : words)
  {
    if (isNumber(word))
    {
      if (atoi(word.c_str()) > pow(2, 20) - 1)
        return -1;
      myStack.push(word);
    }

    else if (word == "DUP")
    {
      if (myStack.empty())
        return -1;
      myStack.push(myStack.top());
    }

    else if (word == "POP")
    {
      if (myStack.empty())
        return -1;
      myStack.pop();
    }

    else if (word == "+")
    {
      if (myStack.size() < 2)
        return -1;
      int last = atoi(myStack.top().c_str());
      if (!isNumber(myStack.top()))
        return -1;
      myStack.pop();
      int secondLast = atoi(myStack.top().c_str());
      if (!isNumber(myStack.top()))
        return -1;
      myStack.pop();
      if (secondLast + last >= pow(2, 20) - 1)
        return -1;
      myStack.push(to_string(secondLast + last));
    }

    else if (word == "-")
    {
      if (myStack.size() < 2)
        return -1;
      int last = atoi(myStack.top().c_str());
      if (!isNumber(myStack.top()))
        return -1;
      myStack.pop();
      int secondLast = atoi(myStack.top().c_str());
      if (!isNumber(myStack.top()))
        return -1;
      myStack.pop();
      myStack.push(to_string(last - secondLast));
    }
  }
  return atoi(myStack.top().c_str());
}

int main()
{
  string S1 = "4 5 6 - 7 +";
  // string S2 = "13 DUP 4 POP 5 DUP + DUP + -";
  // string S3 = "5 6 + -";
  // string S4 = "6 + -";
  // string S5 = "3 DUP 5 - -";
  // string S6 = "1048575 DUP +";
  // string S7 = "46 54 62 - 721 +";
  string S8 = "3 DUP 5 - -";

  cout << solution(S1) << endl;
  // cout << solution(S2) << endl;
  // cout << solution(S3) << endl;
  // cout << solution(S4) << endl;
  // cout << solution(S5) << endl;
  // cout << solution(S6) << endl;
  cout << solution(S8) << endl;
  return 0;
}