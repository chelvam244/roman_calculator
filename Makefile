# Use the correct path for -L, -I and -rpath
c_compile:
	cd roman_conversion; make
	gcc -L$(shell pwd)/roman_conversion -Wl,-rpath=$(shell pwd)/roman_conversion -o roman_calc roman_calc.c -I$(shell pwd)/roman_conversion -lroman
	
clean:
	rm roman_calc
	cd roman_conversion; make clean

