GCC = g++ -std=c++0x
TARGET = ana_sakra
OBJ = ana_sakra.o
CLASSOBJ = MyclassDict.o RunInfo.o V1730ZLEHeader.o ChEvent.o V1730ZLE.o
ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS = $(shell root-config --libs)
DEBUG = -Wall -fPIC
CFLAGS= $(DEBUG) $(ROOTFLAGS)


$(TARGET): $(OBJ) $(CLASSOBJ)
	$(GCC) $^ -o $@ $(CFLAGS) $(ROOTLIBS)
	$(GCC) -shared $(DEBUG) $(CLASSOBJ) -o libMyclass.so

Myclass:
	@echo "Generating dictionary $@..."
	rootcling -f $(@)Dict.cpp -c RunInfo.hpp V1730ZLEHeader.hpp ChEvent.hpp V1730ZLE.hpp LinkDef.h

.cpp.o:
	$(GCC) -c $< $(CFLAGS)

clean:
	rm -f ana_sakra *.o
