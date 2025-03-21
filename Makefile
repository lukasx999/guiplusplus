CXX=clang++
CXXFLAGS=-Wall -Wextra -std=c++23 -pedantic -fsanitize=undefined -ggdb
LIBS=-lraylib
DEPS=button.hh switch.hh

all: gui++

gui++: main.o button.o switch.o
	$(CXX) $(CXXFLAGS) $(LIBS) $^ -o $@

%.o: %.cc Makefile $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm *.o gui++
