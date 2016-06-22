// Author: Aroul M
// Description: This C function converts decimal number into roman numerals.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*char * dec2roman (int num);

void main() {
  // M =1000, D = 500 , C = 100 , L = 50 , X = 10 , V = 5 , I = 1;
  char *str_roman;
  int num;
  int success;
  
  printf("\n Enter the number: ");
  scanf("%u", &num);
  
  str_roman = dec2roman(num);
  
  printf("Roman conversion of num: %s\n", str_roman);
  free(str_roman);
  
}*/

char * dec2roman (int num ) {
  
  char roman[255] = "";
  int  i = 0;
  int  incr = 0;
  int  loop;
  int  roman_deci_base[] = {1000, 500, 100, 50, 10, 5, 1};
  int  deci_exception[]  = {6000, 900, 400, 90, 40, 9, 4};
  char *roman_char_base[] = {"M", "D", "C", "L", "X", "V", "I"};
  char *roman_exception[] = {"MM", "CM", "CD", "XC", "XL", "IX", "IV"};
  
  if(num < 0 || num > 5000) {
    printf("The program currently converts the numbers less than 5000 to Roman numerals\n");
    return "";
  }
  
  do {
    if(num >= roman_deci_base[incr]) {
      if( num >= deci_exception[incr]) {
        strcat(roman,roman_exception[incr]);
        num = num - deci_exception[incr];
      } else {
        if(incr%2 == 0)
          loop = num / roman_deci_base[incr];
        else
          loop = 1;
        for(i=0;i<loop;i++) {
          strcat(roman,roman_char_base[incr]);
        }
        num = num - loop * roman_deci_base[incr];
      }
    }
    incr++;
  } while (num > 0);
  
  char *final_value = malloc(strlen(roman));
  strcpy(final_value,roman);
  return (char *)final_value;
}
