CC = gcc
CFLAGS = -g -Wall -c     # -pg: gprof
LDFLAGS = -lsqlite3
INCLUDES = 

TARGET = sql_exec

SRC := $(wildcard *.c)

OBJ := $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

$(OBJ): $(SRC)
	$(CC) $(INCLUDES) $(CFLAGS) $^

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
	rm -f $(TARGET) $(OBJ) *.db
