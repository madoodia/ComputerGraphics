/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <vector>

int* searchInMatrix(const auto& matrix, int target)
{
  int row = matrix.size();
  int col = matrix[0].size();
  // matrix[0][0] = 0; // this is not allowed

  int* index = new int[2];

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (matrix[i][j] == target)
      {
        index[0] = i;
        index[1] = j;
        return index;
      }
    }
  }
}

void printMatrix(auto& matrix)
{
  int row = matrix.size();
  int col = matrix[0].size();

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main()
{
  std::vector<std::vector<int>> matrix = {{1, 3, 5, 7},
                                          {10, 11, 16, 20},
                                          {23, 30, 34, 50},
                                          {7, 9, 11, 13}};

  int* index = searchInMatrix(matrix, 34);
  std::cout << "index: " << index[0] << ", " << index[1] << std::endl;

  printMatrix(matrix);

  return 0;
}
