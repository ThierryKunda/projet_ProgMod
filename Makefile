CXX = g++
CXXFLAGS = -Wall -std=c++11 -g
EXEC_FILES = tests

all: tests

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

coords.o: coord.cpp coord.hpp
	$(CXX) $(CXXFLAGS) -c $<

tests.o: doctest.h
	$(CXX) $(CXXFLAGS) -c $<

tests: tests.o coords.o
	$(CXX) -o $@ $^ $(LDFLAGS)

clean: 
	rm -f *.o $(EXEC_FILES)
