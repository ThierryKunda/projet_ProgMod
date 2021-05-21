CXX = clang++
CXXFLAGS = -Wall -std=c++11 -g
EXEC_FILES = test tests ecrfich

all: principal


principal.o: principal.cpp doctest.h

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

test: test.o ecrfich.o coord.o fourmi.o place.o grille.o
	$(CXX) -o $@ $^

principal: principal.o ecrfich.o coord.o fourmi.o place.o grille.o
	$(CXX) -o $@ $^
clean:
	rm -f *.o *.ppm *.gif $(EXEC_FILES)
