CXX=clang++
CXXFLAGS=-Wall -Wextra -std=c++23 -pedantic -fsanitize=address,undefined -ggdb
LIBS=-lraylib

all: ui

ui: main.cc
	$(CXX) $(CXXFLAGS) $(LIBS) $^ -o ui

%.o: %.cc Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@
