CC = g++
CFLAGS = -g -Wall -std=c++0x -c     # -pg: gprof
LFLAGS = -lpthread                  # -pg: gprof (both compile and link need -pg)

EXEC = \
      mthread

OBJ = \
	  mthread.o

SRC = \
	  mthread.cpp

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LFLAGS)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $^

.PHONY: clean
clean:
	rm -f $(EXEC) $(OBJ)
