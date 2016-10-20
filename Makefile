CC = g++ -Wall - Werror -ansi -pedantic

all: action and command connector interpreter line makeTree node object or pattern semiColon

	$(CC) src/action.cpp src/and.cpp src/command.cpp src/connector.cpp src/interpreter.cpp src/line.cpp 
	src/makeTree.cpp src/node.cpp src/object.cpp src/or.cpp src/pattern.cpp src/semiColon.cpp