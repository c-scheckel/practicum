#include "hw09.h"
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>

#define INV_SYMBOL 36

// useful static helper functions
static int char_to_int(char c);
const char *skip_whitespace(const char *ptr);

long string_to_long(const char *string, const char **endptr, int base) {
  // checking that the first argument is not null, as specified in hw09.h
  assert(string != NULL);

  // setting errno to zero before function body starts
  errno = 0;

  long ret_value = 0;

  // Check if the base provided is invalid, i.e. it is less than 2 or more than
  // 36. Remember that base 0 is valid, and you need to check the string to see
  // if it is octal or hexadecimal.
  //
  // If the base is invalid, set errno to EINVAL and return
  if((base<2 || base >36) && base!= 0){
    errno = EINVAL;
    if(endptr) *endptr = string;
    return 0;
  }
  // Skip over any whitespace present
   string = skip_whitespace(string);
   const char *none = string;
  // Find the sign before the start of the number, if any
  int sign = 1;
  if(string[0] == '-'){
    sign = -1;
    string++;}
  else if(string[0] == '+') string++;

  if (string[0] == '+' || string[0] == '-') {
     if (endptr) *endptr = none;
     return 0;
}
  // Handle the case where base == 0
  if(!base){
    if(string[0] == '0'){
      if(string[1] == 'b' || string[1] == 'B'){
	 base = 2;
	 string+=2;
	}
      else if(string[1] == 'x' || string[1] == 'X'){
	 base = 16;
	 string+=2;
         }
      else base = 8;
       }
    else base = 10; 
  }

 if(base == 16 && string[0] == '0' && (string[1] == 'x' || string[1] == 'X')) string += 2;
  // Continue conversion while
  // 1) the string has not ended
  // 2) the current symbol is valid
  // 3) the current symbol is not a numeric value more than the base
  // Remember to deal with overflow! If overflow occurs, set errno to ERANGE
  int num;
  int check = 0;
  while(string[0] != '\0'){
    num = char_to_int(string[0]);
    if(num == INV_SYMBOL || num >= base) break;
    check = 1;
    if (sign == 1 && (ret_value > (LONG_MAX - num) / base)) {
      errno = ERANGE;
      ret_value = LONG_MAX;
      while (char_to_int(string[0])!= INV_SYMBOL && char_to_int(string[0])< base)string++;
      if (endptr) *endptr = string;
      return ret_value;
    }
    if (sign ==-1 && (-ret_value <(LONG_MIN + num) /base)) {
      errno = ERANGE;
      ret_value = LONG_MIN;
      while (char_to_int(string[0])!= INV_SYMBOL && char_to_int(string[0]) < base) string++;
      if (endptr) *endptr = string;
      return ret_value;
    }
    ret_value = ret_value * base + num;
    string++;
  }
  // Deal with signs

  // If there is no digit conversion, what should endptr be?

  if(!check){
     if(endptr) *endptr = none;
     return 0;
  }
  if(endptr) *endptr = string;

  ret_value = ret_value * sign;

  return ret_value;
}

static int char_to_int(char c) {
  // what if c is '0' -- '9'
  if (isdigit(c)) {
    return c - '0';
  }

  // what if c is 'a' -- 'z'
  if (islower(c)) {
    // only deal with one alphabetic case
    c = toupper(c);
  }

  if (isupper(c)) {
    // 'A' becomes 65 - 65 + 10 = 10, 'B' becomes 11 and so on
    return c - 'A' + 10;
  }

  return INV_SYMBOL;
}

const char *skip_whitespace(const char *ptr) {
  while (isspace(*ptr)) {
    ptr++;
  }

  return ptr;
}
