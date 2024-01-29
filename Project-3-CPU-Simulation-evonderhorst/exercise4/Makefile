# Author: Erich Vonderhorst
# Creation Date: 12/1/2023
# Last Update: 12/1/2023

# Variables
PROG = autosimulation
OBJS = autosimulation.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object File
autosimulation.o:
	$(CC) $(FLAG) -c autosimulation.cpp

# Clean Function
clean:
	rm -f core $(PROG) $(OBJS) Process.o
