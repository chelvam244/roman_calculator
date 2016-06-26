// Author: Aroul M
// Description: This file is the top-level function that implements the addition
// and the subtraction of Roman Numerals. It uses getchar function to read the
// roman numeral arithmetic operation from the terminal. This file checks
// for valid roman numeral operands and also checks for arithmetic operation 
// of either add (+) or sub (-). The appropriate message is displayed on the
// terminal if the invalid expression is entered.
// The necessary functions called in the file are defined in separate files
// and passed to this file through header file.
// NOTE: This calculator currently supports the roman numerals upto MMMMM 
// (decimal value of 5000). The appropriate warnings are displayed if the
// roman numeral conversion involves decimal value greater than 5000.
#include <stdio.h>
#include <stdlib.h>
#include "roman_conversion.h"

void main() {
	//char str_operand1[255];
	//char chr_arith;
	//char str_operand2[255];
	char str_operand1[] = "II";
	char chr_arith = '+';
	char str_operand2[] = "II";
	char *str_result;
	char  c;
	int   incr = 0;
	int   operand1;
	int   operand2;
	int   result;
	
	//str_result = calc_parser();
	str_result = roman_operation(str_operand1, str_operand2, chr_arith);
	printf("%s\n", str_result);
	free(str_result);
}


