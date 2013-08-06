CC = g++
CFLAGS = -g -Wall -c
LFALGS = 

EXEC = \
	  test_driver

OBJ = \
	  test_driver.o \
	  prime.o

SRC = \
	  test_driver.cpp \
	  prime.cpp

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LFLAGS) $^ -o $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $^

clean:
	rm -f $(EXEC) $(OBJ)
