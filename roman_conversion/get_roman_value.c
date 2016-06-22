// Author: Aroul M
// Description: This C function converts roman numeral into its corresponding
// integer value. This value is returned to the calling function. In case of
// invalid roman numeral, the value of -1 is returned.
#include <stdio.h>
#include <string.h>

int get_roman_value (char c) {
  // M =1000, D = 500 , C = 100 , L = 50 , X = 10 , V = 5 , I = 1;
  int value = -1;
  switch(c) {
    case 'M':
      value = 1000;
      break;
    case 'D':
      value = 500;
      break;
    case 'C':
      value = 100;
      break;
    case 'L':
      value = 50;
      break;
    case 'X':
      value = 10;
      break;
    case 'V':
      value = 5;
      break;
    case 'I':
      value = 1;
      break;
    default:
      value = -1;
      break;
  }
  return value;
}
