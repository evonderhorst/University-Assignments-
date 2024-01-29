# Author: Erich Vonderhorst
# Creation Date: 10/11/2023
# Last Update: 10/13/2023

# Variables
PROG = homework5
FLAG = -g -Wall -std=c++11
OBJS = homework5.o PersonData.o CustomerData.o PreferredCustomer.o
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Object Files
homework5.o: PersonData.h CustomerData.h PreferredCustomer.h
	$(CC) $(FLAG) -c homework5.cpp
PersonData.o: PersonData.h
	$(CC) $(FLAG) -c PersonData.cpp
CustomerData.o: CustomerData.h PersonData.h
	$(CC) $(FLAG) -c CustomerData.cpp
PreferredCustomer.o: PreferredCustomer.h CustomerData.h PersonData.h
	$(CC) $(FLAG) -c PreferredCustomer.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(PROG) $(OBJS)
rebuild:
	make clean
	make
