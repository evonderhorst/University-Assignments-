# Author: Erich Vonderhorst
# Creation Date: 10/27/2023
# Last Update: 10/27/2023

# Variables
PROG = exercise3
OBJS = exercise3.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object File
exercise3.o: LinkedList.h
	$(CC) $(FLAG) -c exercise3.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
