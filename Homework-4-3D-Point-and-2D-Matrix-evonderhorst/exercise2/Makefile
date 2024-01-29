# Author: Erich Vonderhorst
# Creation Date: 10/05/2023
# Last Update: 10/05/2023

# Variables
PROG = exercise2
OBJS = exercise2.o Matrix.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object Files
exercise2.o: Matrix.h
	$(CC) $(FLAG) -c exercise2.cpp

Matrix.o: Matrix.h
	$(CC) $(FLAG) -c Matrix.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
