c_compile: dec2roman.c roman2dec.c get_roman_value.c calc_parser.c roman_operation.c
	gcc -c -Wall -Werror -fPIC dec2roman.c roman2dec.c get_roman_value.c calc_parser.c roman_operation.c
	gcc -shared -o libroman.so dec2roman.o roman2dec.o get_roman_value.o calc_parser.o roman_operation.o
	
clean:
	rm libroman.so
	rm *.o

