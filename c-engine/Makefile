CC=cc
CFLAGS=-std=c11 -Wall -Wextra -pedantic -O2
TARGET=timetable_engine
SRC=main.c timetable.c algorithms.c
all: $(TARGET)
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
clean:
	rm -f $(TARGET)
run: all
	./$(TARGET)
