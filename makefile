
TARGET = programa

SRCS = main.c empresa.c

HEADERS = empresa.h definiciones.h

OBJS = main.o empresa.o

CC = gcc
CFLAGS = -Wall -g

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o:
