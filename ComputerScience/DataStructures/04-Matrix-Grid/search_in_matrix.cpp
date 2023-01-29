/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

#define ROWS 2
#define COLS 3

int* searchInMatrix(int matrix[][COLS], int rows, int cols, int target)
{
  int* index = new int[2];

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (matrix[i][j] == target)
      {
        index[0] = i;
        index[1] = j;
        return index;
      }
    }
  }

  index[0] = -1;
  index[1] = -1;
  return index;
}

int main()
{
  int matrix[][COLS] = {{1, 2, 3},
                        {4, 5, 6}};

  int target = 5;

  int* index = searchInMatrix(matrix, ROWS, COLS, target);

  std::cout << "index: " << index[0] << ", " << index[1] << std::endl;

  return 0;
}
