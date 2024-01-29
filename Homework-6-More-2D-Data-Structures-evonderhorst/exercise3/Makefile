# Author: Erich Vonderhorst
# Creation Date: 10/20/2023
# Last Update: 10/20/2023

# Variables
PROG = exercise3
OBJS = exercise3.o Die.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
PROG: $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

# Object Files
exercise3.o: Array2D.h Vector2D.h Die.h
	$(CC) $(FLAG) -c exercise3.cpp

Die.o: Die.h
	$(CC) $(FLAG) -c Die.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
