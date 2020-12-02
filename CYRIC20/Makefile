GCC = g++ -std=c++0x -O2
ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS = $(shell root-config --libs)
DEBUG = -Wall

all: ana_sakra.cpp
	$(GCC) ana_sakra.cpp $(ROOTFLAGS) $(DEBUG) $(ROOTLIBS) -o ana_sakra

clean:
	rm -f ana_sakra *.o
