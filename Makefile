CXX=clang++
CXXFLAGS=-Wall -Wextra -std=c++23 -pedantic -fsanitize=address,undefined -ggdb
LIBS=-lraylib
DEPS=button.hh switch.hh

all: ui

ui: main.cc button.cc switch.cc
	$(CXX) $(CXXFLAGS) $(LIBS) $^ -o ui

%.o: %.cc Makefile $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
