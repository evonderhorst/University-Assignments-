# Author: Erich Vonderhorst
# Creation Date: 10/8/2023
# Last Update: 10/10/2023

# Variables
PROG = exercise2
OBJS = Postfix.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object File
Postfix.o: Queue.h LinkedList.h
	$(CC) $(FLAG) -c Postfix.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
