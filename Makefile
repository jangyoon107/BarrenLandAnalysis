CC = g++
CFLAGS = -g -w -Wall

main: main.o Farm.o Land.o test_main.o
	$(CC) $(CFLAGS) -o BarrenLandAnalysis main.o Farm.o Land.o test_main.o

Farm.o: Farm.cpp Farm.h Land.h
	$(CC) $(CFLAGS) -c Farm.cpp

Land.o: Land.cpp Land.h Point.h
	$(CC) $(CFLAGS) -c Land.cpp

test_main.o: ./Tests/test_main.cpp ./Tests/test_main.h Farm.h Land.h Point.h
	$(CC) $(CFLAGS) -c ./Tests/test_main.cpp

test_unit: test_unit.o Farm.o Land.o
	$(CC) $(CFLAGS) -o test_unit test_unit.o Farm.o Land.o

test_unit.o: ./Tests/test_unit.cpp ./Tests/acutest.h Farm.h Land.h Point.h
	$(CC) $(CFLAGS) -c ./Tests/test_unit.cpp
