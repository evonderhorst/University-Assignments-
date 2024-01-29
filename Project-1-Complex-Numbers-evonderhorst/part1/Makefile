# Author: Erich Vonderhorst
# Creation Date: 10/15/2023
# Last Update: 10/16/2023
PROG = part1
OBJS = Complex.o part1.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

# Object Files
Complex.o: Complex.h
	$(CC) $(FLAG) -c Complex.cpp

part1.o: Complex.h
	$(CC) $(FLAG) -c part1.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
