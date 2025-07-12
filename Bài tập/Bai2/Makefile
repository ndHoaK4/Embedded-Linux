# Makefile

CC = gcc
CFLAGS = -Wall
TARGET = filestat

all: $(TARGET)

$(TARGET): filestat.c
	$(CC) $(CFLAGS) filestat.c -o $(TARGET)

clean:
	rm -f $(TARGET)
