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
	char str_operand1[255];
	char chr_arith;
	char str_operand2[255];
	char *str_result;
	char  c;
	int   incr = 0;
	int   operand1;
	int   operand2;
	int   result;
	
	printf("Roman Calc\n");
	//scanf("%s", str_calc);
	
	// Skip the initial white spaces or tabs
	while((c = getchar()) == ' ' || c == '\t')
	;
	
	if(c == '\n') {
		printf("Only white space or tab enterd and no valid roman numerals entered\n");
		return;
	}else
		str_operand1[incr++] = c; // Start of reading first operand
	
	while((c = getchar()) != ' ' && c != '\t' && c != '\n' && c != '+' && c != '-') {
		if((c == 'M') || (c == 'D') || (c == 'C') || (c == 'L') || (c == 'X') || (c == 'V') || (c == 'I'))
			str_operand1[incr++] = c;
		else {
			printf("Invalid roman numerals entered for operand 1\n");
			return;
		}
	}
	str_operand1[incr] = '\0';		// End of reading first operand
	printf("str-operand 1: %s\n", str_operand1);
	
	if(c == '\n') {
		printf("Arithmetic Operators and Second Operand were not entered\n");
		return;
	}
	
	if(c == '+' || c == '-') {
		chr_arith = c;
	} else
		while((c = getchar()) == ' ' || c == '\t')
			;		// Skip white space or tab
		
		if(c == '+' || c == '-') {
			chr_arith = c;
		} else {
			printf("Invalid arithmetic operator entered\n");
			return;
	}
	printf("Arithmetic operation: %c\n", chr_arith);
	
	incr = 0;  // Initialize the array count for second operand string
	while((c = getchar()) == ' ' || c == '\t')
	;		// Skip white space or tab
	
	if(c == '\n') {
		printf("No valid roman numeral operand 2 entered\n");
		return;
	}else
		str_operand2[incr++] = c; // Start of reading second operand
	
	while((c = getchar()) != ' ' && c != '\t' && c != '\n') {
		if((c == 'M') || (c == 'D') || (c == 'C') || (c == 'L') || (c == 'X') || (c == 'V') || (c == 'I'))
			str_operand2[incr++] = c;
		else {
			printf("Invalid roman numerals entered for operand 2\n");
			return;
		}
	}
	str_operand2[incr] = '\0';		// End of reading second operand
	printf("str-operand2: %s\n",str_operand2);
	
	if(c != '\n') {
		while((c = getchar()) == ' ' || c == '\t')
		;		// Skip white space or tab
	}
	
	if(c != '\n') {
		printf("Invalid entries after entering two operands: %c\n", c);
		return;
	}
	
	// Convert roman numerals into decimal
	operand1 = roman2dec(str_operand1);
	operand2 = roman2dec(str_operand2);
	
	if(chr_arith == '+')
		result = operand1 + operand2;   // Addition of two numbers
	else {
		if(operand1 > operand2)         // Difference between two numbers
			result = operand1 - operand2;
		else
			result = operand2 - operand1;
	}
	
	printf("Operand 1 & 2: %d & %d\n", operand1, operand2);
	printf("Result: %d\n", result);
	
	if(result > 5000) {
		printf("Result of the arithmetic operation is greater than 5000. ");
		printf("Conversion of numbers greater than 5000 to Roman Numerals is not currently supported\n");
	} else if(result < 1) {
		printf("Result of the arithmetic operation is ZERO. ");
		printf("Conversion of ZERO to Roman Numerals is not possible\n");
	} else {
		str_result = dec2roman(result);
		
		printf("Result in Roman Numerals: %s\n", str_result);
		free(str_result);
	}
}


