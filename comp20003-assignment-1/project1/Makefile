# define C compiler & flags
CC = gcc
CFLAGS = -Wall -Wextra -g
# define libraries to be linked (for example -lm)
LIB =

# define sets of source files and object files
SRC = main.c data.c csv.c list.c search.c bit.c
OBJ = $(SRC:.c=.o)

# define the executable name
EXE = dict1

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(LIB)

main.o: main.c data.h csv.h list.h search.h
	$(CC) $(CFLAGS) -c main.c

data.o: data.c data.h csv.h
	$(CC) $(CFLAGS) -c data.c

csv.o: csv.c csv.h data.h
	$(CC) $(CFLAGS) -c csv.c

list.o: list.c list.h data.h
	$(CC) $(CFLAGS) -c list.c

search.o: search.c search.h list.h data.h bit.h
	$(CC) $(CFLAGS) -c search.c

bit.o: bit.c bit.h
	$(CC) $(CFLAGS) -c bit.c

clean:
	rm -f $(OBJ) $(EXE)