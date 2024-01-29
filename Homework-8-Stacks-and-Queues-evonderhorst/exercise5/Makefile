# Author: Erich Vonderhorst
# Creation Date: 11/10/2023
# Last Update: 11/10/2023

# Variables
PROG = exercise5
OBJS = main.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object File
main.o: PriorityQueue.h
	$(CC) $(FLAG) -c main.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
