c_compile: dec2roman.c roman2dec.c get_roman_value.c
	gcc -c -Wall -Werror -fPIC dec2roman.c roman2dec.c get_roman_value.c
	gcc -shared -o libroman.so dec2roman.o roman2dec.o get_roman_value.o
	
clean:
	rm libroman.so

