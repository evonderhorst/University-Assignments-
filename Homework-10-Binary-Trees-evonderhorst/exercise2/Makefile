# Author: Erich Vonderhorst
# Creation Date: 12/8/2023
# Last Update: 12/8/2023

# Variables
PROG = exercise2
OBJS = exercise2.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object File
exercise2.o: BinaryTree.h
	$(CC) $(FLAG) -c exercise2.cpp

# Clean Function
clean:
	rm -f core $(PROG) $(OBJS)
