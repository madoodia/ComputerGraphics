/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

int main()
{
  int value = 1234;
  unsigned int uiv = 4;
  // set a bit
  int mask1 = (1 << 8);
  value = value | mask1;
  // clear a bit
  int mask2 = (1 << 4);
  value = value & ~mask2;
  // toggle a bit
  int mask3 = (1 << 4);
  value = value ^ mask3;
  value = value ^ mask3;
  value = value ^ mask3;

  // checking a bit is set or not
  int mask4 = (1 << 3);
  if (value & mask4)
  {
    // Bit is set
  }
  else
  {
    // Bit is cleared
  }

  // get the rightmost set bit
  int rightmostSetBit = value & -value;

  // check an integer is power of 2 or not
  if ((value & (value - 1)) == 0)
  {
    // power of 2
  }
  else
  {
    // not power of 2
  }

  // multiply by 2
  int mul2 = value << 1;

  // divide by 2
  int div2 = value >> 1;

  // find the number of set bits
  int count = 0;
  while (value)
  {
    value = value & (value - 1);
    count++;
  }

  // swap two numbers
  int a = 10;
  int b = 20;
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;

  return 0;
}