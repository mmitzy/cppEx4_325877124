CXX = g++

CXXFLAGS = -std=c++11 -Wall -I.

SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp tree.hpp complex.hpp Demo.cpp Test.cpp

OBJ_MAIN = main.o
OBJ_DEMO = Demo.o
OBJ_TEST = Test.o

DEMO_EXEC = demo
EXEC = tree_visualization
TEST_EXEC = test

all: $(EXEC) $(DEMO_EXEC) $(TEST_EXEC)

$(EXEC): $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

$(DEMO_EXEC): $(OBJ_DEMO)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

$(TEST_EXEC): $(OBJ_TEST)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)	

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(DEMO_EXEC) $(TEST_EXEC) *.o

.PHONY: all clean
