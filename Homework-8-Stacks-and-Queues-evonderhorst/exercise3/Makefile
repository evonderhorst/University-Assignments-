# Author: Erich Vonderhorst
# Creation Date: 11/8/2023
# Last Update: 11/10/2023

# Variables:
PROG = exercise3
OBJS = Postfix2.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

#Object File
Postfix2.o:
	$(CC) $(FLAG) -c Postfix2.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
