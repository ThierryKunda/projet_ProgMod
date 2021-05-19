CXX = g++
CXXFLAGS = -Wall -std=c++11 -g
EXEC_FILES = test tests ecrfich

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
	$(CXX) $(CXXFLAGS) -c $<

ecrfich.o: ecrfich.cpp grille.hpp grille.hpp place.hpp fourmi.hpp coord.hpp
	$(CXX) $(CXXFLAGS) -c $<
principal.o: principal.cpp ecrfich.hpp grille.hpp grille.hpp place.hpp fourmi.hpp coord.hpp
	$(CXX) $(CXXFLAGS) -c $<
test: principal.o ecrfich.o test.o coord.o fourmi.o place.o grille.o
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o *.ppm *.gif $(EXEC_FILES)
