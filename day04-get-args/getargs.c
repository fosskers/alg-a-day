#include <stdio.h>

int main(int argc, char **argv) {
  // Turns out these guys right here are the command line args.
  // Just grab them and go, like so:
  int count;

  if(argc > 1) {
    printf("You passed: ");

    // Remember that argv is an array of 'strings'.
    for(count = 1; count < argc; count++)
      printf("%s ", argv[count]);
    printf("\n");
  }

  return 0;
}
