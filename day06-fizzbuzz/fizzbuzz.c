// The "Intro to That Thing Called Programming 101" solution in C.

#include <stdio.h>

int main() {
  int count, printed;

  for(count = 1; count < 101; count++) {
    printed = 0;  // Did we print something?

    if(count % 3 == 0) {
      printf("Fizz");
      printed = 1;
    }
    if(count % 5 == 0) {
      printf("Buzz");
      printed = 1;
    }
    if(!printed)
      printf("%d", count);
    printf("\n");  // Ninja the newline in there.
  }

  return 0;
}
