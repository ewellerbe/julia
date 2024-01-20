 #target, dependency, command

 #variables
CC = g++
CFLAGS = -c -Wall -std=c++11
TARGET = julia

# default target
all: build
			@echo "All Done!"

build: julia.o Utility.o ComplexPlane.o ColorLUT.o
				$(CC) julia.o Utility.o ComplexPlane.o ColorLUT.o -o $(TARGET)

julia.o: julia.cpp
				$(CC) $(CFLAGS) julia.cpp

Utility.o: Utility.cpp
				$(CC) $(CFLAGS) Utility.cpp

ComplexPlane.o: ComplexPlane.cpp
				$(CC) $(CFLAGS) ComplexPlane.cpp

ColorLUT.o: ColorLUT.cpp
				$(CC) $(CFLAGS) ColorLUT.cpp


clean:
				rm -rf *o *ppm $(TARGET)

run:
				./$(TARGET)
