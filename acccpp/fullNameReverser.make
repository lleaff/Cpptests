CXX=g++

all: fullNameReverser fullNameReverserTest

fullNameReverser:
	$(CXX) fullNameReverser.cpp -o fullNameReverser

fullNameReverserTest:
	$(CXX) fullNameReverserTest.cpp -o fullNameReverserTest
