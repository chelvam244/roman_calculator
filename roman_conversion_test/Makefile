CFLAGS=-Wall
LIBS=-lcheck

all: calc-test

calc-test: c_compile
	gcc -L$(shell pwd)/../roman_conversion -Wl,-rpath=$(shell pwd)/../roman_conversion -o roman_calc_test roman_calc_test.c -I$(shell pwd)/../roman_conversion -lroman -lcheck $(shell pkg-config --cflags --libs check)
	./roman_calc_test

c_compile:
	cd ../roman_conversion; make
	

clean:
	cd ../roman_conversion; make clean
	rm roman_calc_test

