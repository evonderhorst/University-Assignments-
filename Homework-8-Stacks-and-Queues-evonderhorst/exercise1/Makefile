# Author: Erich Vonderhorst
# Creation Date: 10/8/2023
# Last Update: 10/10/2023

# Variables
PROG = exercise1
OBJS = StackQueueTest.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object File
StackQueueTest.o: Queue.h Stack.h LinkedList.h
	$(CC) $(FLAG) -c StackQueueTest.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
