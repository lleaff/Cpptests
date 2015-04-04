CC=g++

all: fullNameReverser fullNameReverserTest

fullNameReverser:
	$CC fullNameReverser.cpp -o fullNameReverser

fullNameReverserTest:
	$CC fullNameReverserTest.cpp -o fullNameReverserTest
