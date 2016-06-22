// Author: Aroul M
// Description: This C function converts roman numerals into decimal number.

#include <stdio.h>
#include <string.h>
#include "roman_conversion.h"

/*int roman2dec (char * str_num);

void main() {
  
  char * str_num;
  int    num;
  
  printf("Enter Roman Numerals: ");
  scanf("%s", str_num);
  
  num = roman2dec(str_num);
  
  printf("Roman literal %s converted to : %d\n",str_num, num);
}*/

int roman2dec (char * str_num) {
  
  int  len;
  int  num = 0;
  int  i;
  int  value = 0;
  int  prev_value = 0;
  
  len = strlen(str_num);
  //printf("Length of str_num: %d\n", len);
  
  if(len > 0) {
    for(i=len-1;i>=0;i--) {
	  value = get_roman_value(str_num[i]);
      if(value > 0) {
        if(prev_value > value)
          num -= value;
        else
          num += value;
      } else {
        printf("Invalid Input\n");
        return -1;
      }
      prev_value = value;
    }
  } else {
    printf("Invalid Input - String length is zero\n");
    return -1;
  }
  
  return num;
}

