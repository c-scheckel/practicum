#include "hw09.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

// suggested testing function declaration
static void check_string_to_long(const char *string, int base){
	const char* testptr;
        char* actptr;
	errno=0;
	long test = string_to_long(string, &testptr, base);
        int test_err = errno;
	long actual = strtol(string, &actptr, base);
        int actual_err = errno;

	printf("\ntest:  %ld, %d", test, test_err);
        printf("\nactual: %ld, %d", actual, actual_err);
}

int main(int argc, char **argv) {

  fprintf(stderr, "Welcome to ECE264, we are working on HW09!\n\n");

  // test here
  check_string_to_long("99", 10);
  check_string_to_long("+99", 10);
  check_string_to_long("-99", 10);
  check_string_to_long("0xff", 0);
  check_string_to_long("0xff", 16);
  check_string_to_long("0174", 8);
  check_string_to_long("0101", 2);
  check_string_to_long("  99", 10);
  check_string_to_long("  0xFF", 16);
  check_string_to_long("+-1", 10);
  check_string_to_long("01177", 0);
  check_string_to_long("111111111111111111111111", 10);
  check_string_to_long("-111111111111111111111111", 10);
  return EXIT_SUCCESS;
}
