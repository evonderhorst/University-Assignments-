# Author: Erich Vonderhorst
# Creation Date: 10/27/2023
# Last Update: 10/27/2023

# Variables
PROG = exercise4
OBJS = exercise4.o Shape.o Rectangle.o Square.o Triangle.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object Files
Shape.o: Shape.h
	$(CC) $(FLAG) -c Shape.cpp

Rectangle.o: Rectangle.h
	$(CC) $(FLAG) -c Rectangle.cpp

Square.o: Square.h
	$(CC) $(FLAG) -c Square.cpp

Triangle.o: Triangle.h
	$(CC) $(FLAG) -c Triangle.cpp

exercise4.o: LinkedList.h Shape.h Rectangle.h Square.h Triangle.h
	$(CC) $(FLAG) -c exercise4.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
