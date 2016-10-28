#Makefile must have Targets: all, rshell 

#Variables
COMP = g++ -Wall -Werror -ansi -pedantic
FILES = main.cpp src/action.cpp src/and.cpp src/command.cpp src/connector.cpp src/interpreter.cpp src/line.cpp src/node.cpp src/object.cpp src/or.cpp src/pattern.cpp src/semiColon.cpp

#src/makeTree.cpp

#Targets
all: $(FILES) 
	$(COMP) $(FILES)

clean:
	rm -rf *~ *.o
	
clear:
	rm -rf *~ *.o a.out


# fix later this is poor makefile construction because it literally just does a massive compilation of all files every time