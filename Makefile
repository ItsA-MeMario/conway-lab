CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -D_XOPEN_SOURCE=600
PREFIX  ?= /usr/local

SRCS    = main.c life.c
OBJS    = $(SRCS:.c=.o)
TARGET  = conway

.PHONY: all clean install

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c life.h
	$(CC) $(CFLAGS) -c -o $@ $<

life.o: life.c life.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

install: $(TARGET)
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
