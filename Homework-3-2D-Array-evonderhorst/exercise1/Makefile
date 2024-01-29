# Author: Erich Vonderhorst
# Creation Date: 9/21/2023
# Last Update: 9/21/2023

# Variables
PROG = exercise1
OBJS = exercise1.o exercise1imp.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS) Array2D.h
	$(CC) $(FLAG) -o $(PROG) $(OBJS)

# Object Files
exercise1.o: Array2D.h
	$(CC) $(FLAG) -c exercise1.cpp

exercise1imp.o: Array2D.h
	$(CC) $(FLAG) -c exercise1imp.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
