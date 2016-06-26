#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman_conversion.h"

char * calc_parser() {
	char *str_result;
	char  c;
	char str_operand1[255];
	int   incr = 0;
	char chr_arith;
	char str_operand2[255];
	int   operand1;
	int   operand2;
	int   result;
	
	printf("*****************Roman Calc*********************\n");
	printf("Enter Arithmetic expression similar to the one shown below:\n");
	printf("(Roman_Numeral_operand1 +/- Roman_Numeral_Operand2):\n");
	//scanf("%s", str_calc);
	
	// Skip the initial white spaces or tabs
	while((c = getchar()) == ' ' || c == '\t')
	;
	
	if(c == '\n') {
		//printf("Only white space or tab enterd and no valid roman numerals entered\n");
		str_result = malloc(strlen("Enter Roman Arithmetic Expression"));
		strcpy(str_result, "Enter Roman Arithmetic Expression");
		return (char *)str_result;
	}else
		str_operand1[incr++] = c; // Start of reading first operand
	
	while((c = getchar()) != ' ' && c != '\t' && c != '\n' && c != '+' && c != '-') {
		if((c == 'M') || (c == 'D') || (c == 'C') || (c == 'L') || (c == 'X') || (c == 'V') || (c == 'I'))
			str_operand1[incr++] = c;
		else {
			//printf("Invalid roman numerals entered for operand 1\n");
			str_result = malloc(strlen("Invalid Operand 1 Roman Numerals"));
			strcpy(str_result, "Invalid Operand 1 Roman Numerals");
			return (char *)str_result;
		}
	}
	str_operand1[incr] = '\0';		// End of reading first operand
	
	if(c == '\n') {
		//printf("Arithmetic Operators and Second Operand were not entered\n");
		str_result = malloc(strlen("Invalid Arithmetic Expression"));
		strcpy(str_result, "Invalid Arithmetic Expression");
		return (char *)str_result;
	}
	
	if(c == '+' || c == '-') {
		chr_arith = c;
	} else
		while((c = getchar()) == ' ' || c == '\t')
			;		// Skip white space or tab
		
	if(c == '+' || c == '-') {
		chr_arith = c;
	} else {
		//printf("Invalid arithmetic operator entered\n");
		str_result = malloc(strlen("Invalid arithmetic operator"));
		strcpy(str_result, "Invalid arithmetic operator");
		return (char *)str_result;
	}
	//printf("Arithmetic operation: %c\n", chr_arith);
	
	incr = 0;  // Initialize the array count for second operand string
	while((c = getchar()) == ' ' || c == '\t')
	;		// Skip white space or tab
	
	if((c == '\n') || (c == '+') || (c ==  '-')) {
		//printf("No valid roman numeral operand 2 entered\n");
		str_result = malloc(strlen("No Operand 2 roman Numerals"));
		strcpy(str_result, "No Operand 2 roman Numerals");
		return (char *)str_result;
	}else
		str_operand2[incr++] = c; // Start of reading second operand
	
	while((c = getchar()) != ' ' && c != '\t' && c != '\n') {
		if((c == 'M') || (c == 'D') || (c == 'C') || (c == 'L') || (c == 'X') || (c == 'V') || (c == 'I'))
			str_operand2[incr++] = c;
		else {
			//printf("Invalid roman numerals entered for operand 2\n");
			str_result = malloc(strlen("Invalid Operand 2 roman Numerals"));
			strcpy(str_result, "Invalid Operand 2 roman Numerals");
			return (char *)str_result;
		}
	}
	str_operand2[incr] = '\0';		// End of reading second operand
	//printf("str-operand2: %s\n",str_operand2);
	
	if(c != '\n') {
		while((c = getchar()) == ' ' || c == '\t')
		;		// Skip white space or tab
	}
	
	if(c != '\n') {
		//printf("Invalid entries after entering two operands: %c\n", c);
		str_result = malloc(strlen("Invalid Entries after arithmetic expression"));
		strcpy(str_result, "Invalid Entries after arithmetic expression");
		return (char *)str_result;
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
	
	//printf("Operand 1 & 2: %d & %d\n", operand1, operand2);
	//printf("Result: %d\n", result);
	
	if(result > 5000) {
		//printf("Result of the arithmetic operation is greater than 5000. ");
		//printf("Conversion of numbers greater than 5000 to Roman Numerals is not currently supported\n");
		str_result = malloc(strlen("Conversion greater than 5000 not supported"));
		strcpy(str_result, "Conversion greater than 5000 not supported");
	} else if(result < 1) {
		//printf("Result of the arithmetic operation is ZERO. ");
		//printf("Conversion of ZERO to Roman Numerals is not possible\n");
		str_result = malloc(strlen("Arithmetic operation result = ZERO"));
		strcpy(str_result, "Arithmetic operation result = ZERO");
	} else {
		str_result = dec2roman(result);
		//printf("Result in Roman Numerals: %s\n", str_result);
	}
	return (char *)str_result;
}

