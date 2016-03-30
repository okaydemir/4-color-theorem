CC = g++
CFLAGS  = -std=c++11 -g -Wall

four_color: four_color.o 
	$(CC) $(CFLAGS) four_color.o -o four_color

four_color.o: four_color.cpp
	$(CC) $(CFLAGS) -c four_color.cpp

clean:
	rm -f *.o
	rm -f four_color
