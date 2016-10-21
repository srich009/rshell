#Makefile must have Targets: all, rshell 

#Variables
COMP = g++ -Wall -Werror -ansi -pedantic
FILES = src/action.cpp src/and.cpp src/command.cpp src/interpreter.cpp src/line.cpp src/makeTree.cpp src/node.cpp src/or.cpp src/pattern.cpp src/semiColon.cpp

#Targets
all: $(FILES) 
	$(COMP) $(FILES)

#rshell: 


clean:
	rm -rf *~ *.o
	
clear:
	rm -rf *~ *.o a.out


### NOT SURE WHAT THIS DOES????
#$(CC) src/action.cpp src/and.cpp src/command.cpp src/connector.cpp src/interpreter.cpp src/line.cpp 
#src/makeTree.cpp src/node.cpp src/object.cpp src/or.cpp src/pattern.cpp src/semiColon.cpp