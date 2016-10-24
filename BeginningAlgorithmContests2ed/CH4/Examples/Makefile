CC = g++
CFLAGS = -Wall
SRCS =$(wildcard *.cpp)
OBJS =$(patsubst %.cpp, %, $(SRCS))
.PHONY:all clean
all:$(OBJS)
%:%.cpp
	$(CC) $(CFLAGS) -o $@ $<
clean:
	rm -f $(OBJS)