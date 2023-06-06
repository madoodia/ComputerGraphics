/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

struct Test
{
  char a;
  int c;
  char b;
};

int main()
{
  Test t;
  t.a = 1;
  t.b = 2;
  t.c = 3;

  int x = 0xabc;
  int y = (x >> 4);
  int z = (x << 4);
  return 0;
}