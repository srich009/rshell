# Variables
COMP = g++
FLAGS = -Wall -Werror -ansi -pedantic
DEBUG = -g
OFILES = src/action.o src/interpreter.o src/line.o src/object.o src/pattern.o src/node.o

# Targets
all: main.cpp $(OFILES) | bin
	$(COMP) $(FLAGS) main.cpp $(OFILES) -o rshell && mv rshell bin/
	
debug: main.cpp $(OFILES) | bin
	$(COMP) $(FLAGS) $(DEBUG) main.cpp $(OFILES) -o rshell && mv rshell bin/
	
pattern.o: src/line.cpp header/line.h src/action.cpp header/action.h src/interpreter.cpp header/interpreter.h src/pattern.cpp header/pattern.h
	$(COMP) $(FLAGS) -c src/pattern.cpp

line.o: src/object.cpp header/object.h src/line.cpp header/line.h
	$(COMP) $(FLAGS) -c src/line.cpp
	
interpreter.o: src/object.cpp header/object.h src/interpreter.cpp header/interpreter.h
	$(COMP) $(FLAGS) -c src/interpreter.cpp
	
action.o: src/object.cpp header/object.h src/action.cpp header/action.h
	$(COMP) $(FLAGS) -c src/action.cpp
	
object.o: src/object.cpp header/object.h
	$(COMP) $(FLAGS) -c src/object.cpp

node.o: 
	$(COMP) $(FLAGS) -c src/node.cpp

bin:
	mkdir bin

clean:
	rm -rf *~ src/*.o && rm -rf bin
