// Counts the number of lines in a file.

#include <stdio.h>

int main() {
  char c;
  int count = 1;  // Number of lines.

  while((c = getchar()) != EOF)
    if(c == '\n')
      count++;

  printf("%d\n", count);

  return 0;
}
