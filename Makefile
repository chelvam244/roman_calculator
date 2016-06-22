# Use the correct path for -L, -I and -rpath
c_compile:
	cd roman_conversion; make
	gcc -L/home/aroul/roman_calc_final/roman_conversion -Wl,-rpath=/home/aroul/roman_calc_final/roman_conversion -o roman_calc roman_calc.c -I/home/aroul/roman_calc_final/roman_conversion -lroman
	
clean:
	rm roman_calc
	cd roman_conversion; make clean

