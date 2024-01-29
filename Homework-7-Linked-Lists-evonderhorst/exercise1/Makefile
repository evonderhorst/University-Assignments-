# Author: Erich Vonderhorst
# Creation Date: 10/27/2023
# Last Update: 10/27/2023

# Variables
PROG = exercise1
OBJS = exercise1.o NumberList.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object Files
exercise1.o:
	$(CC) $(FLAG) -c exercise1.cpp

NumberList.o:
	$(CC) $(FLAG) -c NumberList.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
