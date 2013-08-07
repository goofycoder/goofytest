CC = g++
CFLAGS = -g -Wall -std=c++0x -c
LFALGS = 

EXEC = \
	  test_driver

OBJ = \
	  test_driver.o \
	  prime.o \
	  anagram.o \
	  palindrome.o

SRC = \
	  test_driver.cpp \
	  prime.cpp \
	  anagram.cpp \
	  palindrome.cpp

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LFLAGS) $^ -o $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $^

clean:
	rm -f $(EXEC) $(OBJ)
