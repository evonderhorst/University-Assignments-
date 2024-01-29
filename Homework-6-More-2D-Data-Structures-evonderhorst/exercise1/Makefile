# Author: Erich Vonderhorst
# Creation Date: 10/18/2023
# Last Update: 10/18/2023

# Variables
PROG = exercise1
OBJS = exercise1.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
PROG: $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

# Object Files
exercise1.o: Array2D.h
	$(CC) $(FLAG) -c exercise1.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
