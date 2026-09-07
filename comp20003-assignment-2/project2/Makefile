# define C compiler & flags
CC = gcc
CFLAGS = -Wall -Wextra -g
# define libraries to be linked (for example -lm)
LIB =

# define sets of source files and object files
SRC = main.c data.c csv.c list.c search.c bit.c patricia.c editDistance.c
OBJ = $(SRC:.c=.o)

# define the executable name
EXE1 = dict1
EXE2 = dict2

$(EXE1): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE1) $(OBJ) $(LIB)

$(EXE2): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE2) $(OBJ) $(LIB)

main.o: main.c data.h csv.h patricia.h search.h list.h
	$(CC) $(CFLAGS) -c main.c -o main.o

data.o: data.c data.h
	$(CC) $(CFLAGS) -c data.c -o data.o

csv.o: csv.c csv.h data.h
	$(CC) $(CFLAGS) -c csv.c -o csv.o

bit.o: bit.c bit.h
	$(CC) $(CFLAGS) -c bit.c -o bit.o

list.o: list.c list.h data.h
	$(CC) $(CFLAGS) -c list.c -o list.o

patricia.o: patricia.c patricia.h data.h list.h bit.h
	$(CC) $(CFLAGS) -c patricia.c -o patricia.o

editDistance.o: editDistance.c editDistance.h
	$(CC) $(CFLAGS) -c editDistance.c -o editDistance.o

search.o: search.c search.h patricia.h bit.h data.h list.h editDistance.h
	$(CC) $(CFLAGS) -c search.c -o search.o

clean:
	rm -f $(OBJ) $(EXE1) $(EXE2)
