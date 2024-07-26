SRCS := src/main.cpp src/todo/todo.cpp src/console/console.cpp
SRCS += src/input_error/input_error.cpp src/save/save.cpp

HOST := $(shell uname -s)

ifeq ($(HOST), Darwin)
	CXX := clang++
else
	CXX := g++
endif

all: $(SRCS)
	$(CXX) -Wall -Wextra -std=c++11 -o todos $(SRCS)

docs:
	doxygen

run: all
	./todos

clean:
	-rm -r docs/ todos saved_todos.txt
