#include <stdio.h>

int main()
{
  char name[3][5] = {"Rena", "Yuki", "Mimi"};

  printf("%s\n%s\n%s", name[0], name[1], name[2]);
  printf("%s\n", name[0][1]);

  return 0;
}