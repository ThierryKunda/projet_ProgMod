CXX = g++
CXXFLAGS = -Wall -std=c++11 -g
EXEC_FILES = test

all: test

test.o: test.cpp doctest.h
	$(CXX) $(CXXFLAGS) -c $<
    
coord.o: coord.cpp coord.hpp
	$(CXX) $(CXXFLAGS) -c $<

fourmi.o: fourmi.cpp fourmi.hpp coord.hpp
	$(CXX) $(CXXFLAGS) -c $<

place.o: place.cpp place.hpp fourmi.hpp coord.hpp
	$(CXX) $(CXXFLAGS) -c $<

grille.o: grille.cpp grille.hpp place.hpp fourmi.hpp coord.hpp

test: test.o coord.o fourmi.o place.o grille.o
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o $(EXEC_FILES)
