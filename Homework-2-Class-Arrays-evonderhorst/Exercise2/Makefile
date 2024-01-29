# Author: Erich Vonderhorst
# Creation Date: 9/22/2023
# Last Update: 9/22/2023

# Variables
PROG = homework2e2
OBJS = homework2e2.o homework2e2imp.o
FLAG = -g -Wall
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) $(FLAG) -o $(PROG) $(OBJS)

# Object Files
homework2e2.o: StateData.h
	$(CC) $(FLAG) -c homework2e2.cpp

homework2e2imp.o: StateData.h
	$(CC) $(FLAG) -c homework2e2imp.cpp

# Clean Function
clean:
	rm -f core $(PROG) $(OBJS)
