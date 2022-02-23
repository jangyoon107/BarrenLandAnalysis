CC = g++
CFLAGS = -g -Wall


all: main.o Farm.o Land.o
	$(CC) $(CFLAGS) -o BarrenLandAnalysis main.o Farm.o Land.o

main.o: main.cpp Farm.h Point.h
	$(CC) $(CFLAGS) -c main.cpp

Farm.o: Farm.cpp Farm.h Land.h
	$(CC) $(CFLAGS) -c Farm.cpp

Land.o: Land.cpp Land.h Point.h
	$(CC) $(CFLAGS) -c Land.cpp
