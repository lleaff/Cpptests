CXX=g++
FLAGS=-g

all: fullNameReverser fullNameReverserTest

fullNameReverser:
	$(CXX) $(FLAGS) $(CXXFLAGS) fullNameReverser.cpp -o $@

fullNameReverserTest:
	$(CXX) $(FLAGS) $(CXXFLAGS) fullNameReverserTest.cpp -o $@
