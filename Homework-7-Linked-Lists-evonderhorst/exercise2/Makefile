# Author: Erich Vonderhorst
# Creation Date: 10/27/2023
# Last Update: 10/27/2023

# Variables
PROG = exercise2
OBJS = exercise2.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object File
exercise2.o: LinkedList.h
	$(CC) $(FLAG) -c exercise2.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
