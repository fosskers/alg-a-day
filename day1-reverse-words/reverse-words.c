// Reverse the order of words in a string.

#include <stdio.h>
#include <string.h>

void reverse_words(char *);
void reverse(int, int, char *);

int main(int argc, char *argv[]) {
  int len;

  if(argc > 1) {
    reverse_words(argv[1]);
    printf("%s\n", argv[1]);
  }

  return 0;
}

void reverse_words(char *line) {
  // Detects where words start and begin, and calls reverse().
  int word_start, word_end, in_word, count;
  int lim = strlen(line);
  char curr;

  // Reverse individual words.
  for(count = 0; count < lim; count++) {
    curr = line[count]; 
    
    if(!in_word && curr != ' ') {
      in_word = 1;
      word_start = count;
    } 
    else if(in_word && curr == ' ') {
      in_word = 0;
      word_end = count - 1;
      reverse(word_start, word_end, line);
    }
    else if(count == lim - 1)
      reverse(word_start, count, line);
  }

  // Reverse entire string.
  reverse(0, lim-1, line);
}

void reverse(int lower, int upper, char *line) {
  // Reverses the chars in a string.
  int lim = (upper + lower) / 2;
  char swap;

  for(lower = lower; lower <= lim; lower++) {
    swap = line[lower];
    line[lower] = line[upper];
    line[upper] = swap;
    upper--;
  }
}

