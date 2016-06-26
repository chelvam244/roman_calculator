// Author: Aroul M
// Description: This C function accepts two operands in roman numeral string format
// and the arithmetic operator (ONly ADD and SUB operations are supported). This
// function outputs the arithmetic operation result in roman numeral format.
// This function checks the operands for valid roman numeral characters after
// ignoring white space and tab at both beginning and the end of the operand
// strings. It also checks for either ADD or SUB operator. If the operands and
// the arithmetic operators are valid, the operand strings are converted into
// decimal values and the appropriate arithmetic operations are performed. The
// arithmetic result is then converted into roman numeral string which is 
// returned to the calling function.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman_conversion.h"

char * roman_operation (char * str_operand1, char * str_operand2, char arith) {
	int num_operand1;
	int num_operand2;
	int result;
	char operand1[100];
	char operand2[100];
	char * str_result;
	char c;
	int incr;
	int skip;
	int end_space_incr;
	
	// Check operand 1 for valid roman numerals
	skip = 0;   // Skip whitespace and tab in the beginning of the string
	while((c=str_operand1[skip]) == ' ' || c == '\t')
		skip++;
	
	incr = 0;
	end_space_incr = 0;
	while((c = str_operand1[incr+skip]) != '\n' && c != '\0') {
		if((end_space_incr == 0) && ((c == 'M') || (c == 'D') || (c == 'C') || (c == 'L') || (c == 'X') || (c == 'V') || (c == 'I')))
			operand1[incr++] = c;
		else if(c == ' ' || c == '\t') {
			operand1[incr] = '\0';
			end_space_incr++;
			incr++;
		} else {
			//printf("Invalid roman numerals entered for operand 1\n");
			str_result = malloc(strlen("Invalid Operand 1 Roman Numerals"));
			strcpy(str_result, "Invalid Operand 1 Roman Numerals");
			return (char *)str_result;
		}
	}
	
	if(incr == 0) {  // Only white space or/and tab in operand1 and no alphanumeric characters present
		//printf("Only white space or tab enterd and no valid roman numerals entered\n");
		str_result = malloc(strlen("Operand1: Enter Roman Arithmetic Expression"));
		strcpy(str_result, "Operand1: Enter Roman Arithmetic Expression");
		return (char *)str_result;
	}
	
	if(end_space_incr == 0)
		operand1[incr] = '\0';
	
	// Check operand 2 for valid roman numerals
	skip = 0;   // Skip whitespace and tab in the beginning of the string
	while((c=str_operand2[skip]) == ' ' || c == '\t')
		skip++;
		
	incr = 0;
	end_space_incr = 0;
	while((c = str_operand2[incr+skip]) != '\n' && c != '\0') {
		if((end_space_incr == 0) && ((c == 'M') || (c == 'D') || (c == 'C') || (c == 'L') || (c == 'X') || (c == 'V') || (c == 'I')))
			operand2[incr++] = c;
		else if(c == ' ' || c == '\t') {
			operand2[incr] = '\0';
			end_space_incr++;
			incr++;
		} else {
			//printf("Invalid roman numerals entered for operand 1\n");
			str_result = malloc(strlen("Invalid Operand 2 Roman Numerals"));
			strcpy(str_result, "Invalid Operand 2 Roman Numerals");
			return (char *)str_result;
		}
	}
	
	if(incr == 0) {  // Only white space or/and tab in operand1 and no alphanumeric characters present
		//printf("Only white space or tab enterd and no valid roman numerals entered\n");
		str_result = malloc(strlen("Operand2: Enter Roman Arithmetic Expression"));
		strcpy(str_result, "Operand2: Enter Roman Arithmetic Expression");
		return (char *)str_result;
	}
	
	if(end_space_incr == 0)
		operand2[incr] = '\0';
	
	// Check Arithmetic operator. Only + and - allowed
	if(arith == '+' || arith == '-') {
		//chr_arith = c;
	} else {
		//printf("Invalid arithmetic operator entered\n");
		str_result = malloc(strlen("Invalid arithmetic operator"));
		strcpy(str_result, "Invalid arithmetic operator");
		return (char *)str_result;
	}
	
	// Convert roman numerals into decimal
	num_operand1 = roman2dec(operand1);
	num_operand2 = roman2dec(operand2);
	
	if(arith == '+')
		result = num_operand1 + num_operand2;   // Addition of two numbers
	else {
		if(operand1 > operand2)         // Difference between two numbers
			result = num_operand1 - num_operand2;
		else {
			if(num_operand1 > num_operand2)         // Difference between two numbers
			result = num_operand1 - num_operand2;
		else
			result = num_operand2 - num_operand1;
		}
	}
	
	//printf("%d %c %d = %d\n", num_operand1, arith, num_operand2, result);
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
