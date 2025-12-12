CC = clang
CFLAGS = -O2 -Wall

SRC = src/main.c src/bubble.c src/insertion.c src/selection.c src/quick.c src/merge.c src/heap.c src/shell.c src/comb.c src/counting.c src/radix.c src/intro.c
OBJ = $(SRC:.c=.o)

TARGET = sorting

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)