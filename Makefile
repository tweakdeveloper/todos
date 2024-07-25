SRCS := src/main.cpp

HOST := $(shell uname -s)

ifeq ($(HOST), Darwin)
	CXX := clang++
else
	CXX := g++
endif

all: $(SRCS)
	$(CXX) -Wall -Wextra -std=c++11 -o todos $(SRCS)

run: all
	./todos

clean:
	rm todos
