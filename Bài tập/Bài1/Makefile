# Makefile

CC = gcc
CFLAGS = -Wall

# Static Library
STATIC_LIB = libstrutils.a

# Shared Library
SHARED_LIB = libstrutils.so

# Object File
OBJS = strutils.o

all: static shared

static: $(STATIC_LIB)
	$(CC) main.c -L. -lstrutils -o main_static

shared: $(SHARED_LIB)
	$(CC) main.c -L. -lstrutils -o main_shared

$(STATIC_LIB): $(OBJS)
	ar rcs $@ $^

$(SHARED_LIB): strutils.c
	$(CC) -fPIC -c strutils.c -o strutils_shared.o
	$(CC) -shared -o $(SHARED_LIB) strutils_shared.o

strutils.o: strutils.c strutils.h
	$(CC) $(CFLAGS) -c strutils.c

clean:
	rm -f *.o *.a *.so main_static main_shared
