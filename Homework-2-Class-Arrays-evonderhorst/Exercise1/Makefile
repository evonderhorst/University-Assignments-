# Author: Erich Vonderhorst
# Creation Date: 9/20/2023
# Last Update: 9/22/2023

# Variables
PROG = homework2e1
OBJS = homework2e1.o homework2e1imp.o
FLAGS = -g -Wall
CC = g++

# Target
$(PROG) : $(OBJS)
	$(CC) $(FLAGS) -o $(PROG) $(OBJS)

# Object Files
homework1e1.o : IntArrayList.h
	$(CC) $(FLAGS) -c homework2e1.cpp

homework1e1imp.o : IntArrayList.h
	$(CC) $(FLAGS) -c homework2e1imp.cpp

# Clean Function
clean:
	rm -f core $(PROG) $(OBJS)
