# Author: Erich Vonderhorst
# Creation Date: 10/05/2023
# Last Update: 10/05/2023

# Variables
PROG = exercise1
OBJS = exercise1.o Point.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object Files
exercise1.o: Point.h
	$(CC) $(FLAG) -c exercise1.cpp

Point.o: Point.h
	$(CC) $(FLAG) -c Point.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
