# Author: Erich Vonderhorst
# Creation Date: 11/17/2023
# Last Update: 11/17/2023

# Variables
PROG = exercise5
OBJS = Permutations.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object File
NQueens.o:
	$(CC) $(FLAG) -c Permutations.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
