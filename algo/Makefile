CC = g++
CFLAGS = -g -pg -Wall -std=c++0x -c     # -pg: gprof
LFLAGS = -pg                            # -pg: gprof (both compile and link need -pg)

EXEC = \
	  test_driver

OBJ = \
	  test_driver.o \
	  prime.o \
	  anagram.o \
	  fibo.o \
	  palindrome.o

SRC = \
	  test_driver.cpp \
	  prime.cpp \
	  anagram.cpp \
	  fibo.cpp \
	  palindrome.cpp

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LFLAGS) $^ -o $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $^

# Phony targets:
#   - Phony target is one that is not really the name of a file; 
#   - rather it is just a name of a recipe to be executed 
#     when you make an explicit request.
# Two reasons to use phony target:
#   - avoid a confict with afile of the same name
#   - improve performance
#
# Example: ‘make clean’ will run the recipe regardless of whether 
#          there is a file named clean.
.PHONY: clean
clean:
	rm -f $(EXEC) $(OBJ)
