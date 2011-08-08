#include <stdio.h>
#include "primes.h"
#include "intlist.h"

void test(int);
void test_yield_primes(int);

int main() {
  test(0);
  test(1);
  test(2);
  test(3);
  test(4);
  test(5);
  test(10);
  test(29);
  test(100);
  test(104729);
  test(1299709);
  test(7368787);

  test_yield_primes(0);
  test_yield_primes(1);
  test_yield_primes(2);
  test_yield_primes(3);
  test_yield_primes(4);
  test_yield_primes(5);
  test_yield_primes(20);

  return 0;
}

void test(int num) {
  int result;

  printf("Testing %d...\n", num);
  result = is_prime(num);
  printf("Prime? ");
  if(result)
    printf("Yes.\n");
  else
    printf("No.\n");

  printf("\n");
}

void test_yield_primes(int quant) {
  IntList *list = NULL;

  printf("Give me %d primes...\n", quant);
  list = yield_n_primes(quant);
  print_int_list(list);
  printf("\n");
}


