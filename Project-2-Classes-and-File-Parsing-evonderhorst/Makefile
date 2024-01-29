# Author: Erich Vonderhorst
# Creation Date: 11/2/2023
# Last Update: 11/3/2023

# Variables
PROG = project2
OBJS = main.o Date.o FeetInches.o Person.o NBAPlayer.o NFLPlayer.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object Files
main.o: Date.h FeetInches.h Person.h NBAPlayer.h NFLPlayer.h
	$(CC) $(FLAG) -c main.cpp

Date.o: Date.h
	$(CC) $(FLAG) -c Date.cpp

FeetInches.o: FeetInches.h
	$(CC) $(FLAG) -c FeetInches.cpp

Person.o: Person.h
	$(CC) $(FLAG) -c Person.cpp

NBAPlayer.o: NBAPlayer.h
	$(CC) $(FLAG) -c NBAPlayer.cpp

NFLPlayer.o: NFLPlayer.h
	$(CC) $(FLAG) -c NFLPlayer.cpp

# Clean and Rebuild Fumctions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
