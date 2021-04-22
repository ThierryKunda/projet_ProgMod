CXX = g++
CXXFLAGS = -Wall -std=c++11 -g
EXEC_FILES = test

all: test

test.o: test.cpp doctest.h
	$(CXX) $(CXXFLAGS) -c $<
	
test: test.o coord.o
	$(CXX) -o $@ $^ $(LDFLAGS)

coord.o: coord.cpp coord.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean: 
	rm -f *.o $(EXEC_FILES)
