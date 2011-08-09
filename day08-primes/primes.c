#include <math.h>
#include <stdlib.h>
#include "primes.h"
#include "intlist.h"

int is_prime(int num) {
  // Determines if a given number is prime.
  int result = 1;  // Assume success.
  int div = 3;     // We'll only divide by even numbers.
  int lim = (int)sqrt(num) + 1;  // Don't do more work than you have to.

  // Even numbers and numbers less than 2 are definitely not prime.
  if(num == 2)  // But 2 is our friend.
    return 1;
  else if(num < 2 || num % 2 == 0)
    return 0;
  
  for(div = 3; div < lim; div += 2) {
    if(num % div == 0) {
      result = 0;
      break;
    }
  }

  return result;
}

int next_prime(int num) {
  // Given a number, finds the next prime greater than it.
  if(num < 2)
    return 2;
  else if(num == 2)
    return 3;
  else if(num % 2 == 0)
    num -= 1;

  return _next_prime(num);
}

int _next_prime(int num) {
  // Assumes 'num' is odd and positive.
  while(1) {
    num += 2;

    if(is_prime(num))
      break;
  }

  return num;
}

IntList * yield_n_primes(int quant) {
  IntList *list = new_intlist(quant);
  int count;
  int curr;  // The current prime.

  if(list != NULL) {
    // Add the initial primes.
    if(quant > 0)
      list->list[0] = 2;
    if(quant > 1)
      list->list[1] = 3;

    // Add next primes.
    curr = 3;
    for(count = 2; count < quant; count++) {
      curr = _next_prime(curr);
      list->list[count] = curr;
    }
  }

  return list;
}
