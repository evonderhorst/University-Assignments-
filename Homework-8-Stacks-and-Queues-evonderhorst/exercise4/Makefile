# Author: Erich Vonderhorst
# Creation Date: 11/9/2023
# Last Update: 11/10/2023

# Variables
PROG = exercise4
OBJS = Delimiters.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object File
Delimiters.o:
	$(CC) $(FLAG) -c Delimiters.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
