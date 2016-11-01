# Variables
COMP = g++
FLAGS = -Wall -Werror -ansi -pedantic
DEBUG = -g
OFILES = src/action.o src/and.o src/command.o src/connector.o src/interpreter.o src/line.o src/object.o src/or.o src/pattern.o src/semiColon.o

# Targets
all: main.cpp $(OFILES) | bin
	$(COMP) $(FLAGS) main.cpp $(OFILES) -o rshell && mv rshell bin/
	
debug: main.cpp $(OFILES)
	$(COMP) $(FLAGS) $(DEBUG) main.cpp $(OFILES)
	
action.o: src/object.cpp header/object.h src/action.cpp header/action.h
	$(COMP) $(FLAGS) -c src/action.cpp

and.o: src/connector.cpp header/connector.h src/and.cpp header/and.h
	$(COMP) $(FLAGS) -c src/and.cpp

command.o: src/object.cpp header/object.h src/command.cpp header/command.h 
	$(COMP) $(FLAGS) -c src/command.cpp

connector.o: src/object.cpp header/object.h src/connector.cpp header/connector.h 
	$(COMP) $(FLAGS) -c src/connector.cpp

interpreter.o: src/object.cpp header/object.h src/connector.cpp header/connector.h src/command.cpp header/command.h src/semiColon.cpp header/semiColon.h src/or.cpp header/or.h src/and.cpp header/and.h src/interpreter.cpp header/interpreter.h
	$(COMP) $(FLAGS) -c src/interpreter.cpp

line.o: src/object.cpp header/object.h src/line.cpp header/line.h
	$(COMP) $(FLAGS) -c src/line.cpp

object.o: src/object.cpp header/object.h
	$(COMP) $(FLAGS) -c src/object.cpp

or.o: src/connector.cpp header/connector.h src/or.cpp header/or.h
	$(COMP) $(FLAGS) -c src/or.cpp

pattern.o: src/line.cpp header/line.h src/action.cpp header/action.h src/interpreter.cpp header/interpreter.h src/pattern.cpp header/pattern.h
	$(COMP) $(FLAGS) -c src/pattern.cpp

semiColon.o: src/connector.cpp header/connector.h src/semiColon.cpp header/semiColon.h
	$(COMP) $(FLAGS) -c src/semiColon.cpp

bin:
	mkdir bin

clean:
	rm -rf *~ src/*.o && rm -rf bin