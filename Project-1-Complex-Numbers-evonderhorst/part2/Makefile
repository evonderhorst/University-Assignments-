# Author: Erich Vonderhorst
# Creation Date: 10/15/2023
# Last Update: 10/16/2023
PROG = part2
OBJS = Complex.o part2.o
FLAG = -g -Wall -std=c++11
CC = g++

# Target
$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

	# Object Files
Complex.o: Complex.h
	$(CC) $(FLAG) -c Complex.cpp

part2.o: Complex.h bitmap_image.hpp
	$(CC) $(FLAG) -c part2.cpp

# Clean and Rebuild Functions
clean:
	rm -f core $(OBJS) $(PROG)

rebuild:
	make clean
	make
