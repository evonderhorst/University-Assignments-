# Author: Erich Vonderhorst
# Creation Date: 9/21/2023
# Last Update: 9/29/2023

# Variables
PROG = exercise2
OBJS = exercise2.o Array2D.o Die.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS) Array2D.h Die.h
	$(CC) $(FLAG) -o $(PROG) $(OBJS)

# Object Files
exercise2.o: Array2D.h Die.h
	$(CC) $(FLAG) -c exercise2.cpp

Array2D.o: Array2D.h
	$(CC) $(FLAG) -c Array2D.cpp

Die.o: Die.h
	$(CC) $(FLAG) -c Die.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
