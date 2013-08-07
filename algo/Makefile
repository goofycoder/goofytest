CC = g++
CFLAGS = -g -Wall -c
LFALGS = 

EXEC = \
	  test_driver

OBJ = \
	  test_driver.o \
	  prime.o \
	  palindrome.o

SRC = \
	  test_driver.cpp \
	  prime.cpp \
      palindrome.cpp

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LFLAGS) $^ -o $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $^

clean:
	rm -f $(EXEC) $(OBJ)
