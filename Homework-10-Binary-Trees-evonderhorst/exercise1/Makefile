# Author: Erich Vonderhorst
# Creation Date: 12/8/2023
# Last Update: 12/8/2023

# Variables
PROG = exercise1
OBJS = exercise1.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object File
exercise1.o: BinaryTree.h
	$(CC) $(FLAG) -c exercise1.cpp

# Clean Function
clean:
	rm -f core $(PROG) $(OBJS)
