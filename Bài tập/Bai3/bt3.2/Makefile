CC = gcc
CFLAGS = -Wall
TARGET = exec_env

all: $(TARGET)

$(TARGET): exec_env.c
	$(CC) $(CFLAGS) $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
