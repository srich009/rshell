# rshell
UCR CS100 Open Source Shell

##### Authors:
* Sean Richardson - https://github.com/srich009
* Krishna Pakalapati - https://github.com/KrishnaP7

## Introduction
This project is a small working subset of Linux BASH that supports execution of basic commands with logical connectors.

This version of rshell supports limited ```test``` functionality in both forms: Literal and Brackets
* ```test -e test/file/path```
* ```[ -e test/file/path ]```

The ```test``` command can be used with these flags, if no flag the -e flag is assumed
* ```-e``` checks if the file/directory exists
* ```-f``` checks if the file/directory exists and is a regular file
* ```-d``` checks if the file/directory exists and is a directory

## Installation
Run these commands in your terminal to install and run rshell on your system
```Installation
$ git clone https://github.com/srich009/rshell.git

$ cd rshell

$ git checkout hw3

$ make

$ bin/rshell
```

## Bugs
* If the user enters an empty test case ```"[]"``` OR ```test``` followed by no arguments, an execution error occurs, a message is printed.

## Limitations
* The host name obtained by ```gethostname()``` is limited to a maximum of 64 characters. Any name longer than that will be truncated. The hostName buffer is set to "UNKNOWN_HOST" if a failure occurs.
* The user name obtained by ```getlogin_r()``` is limited to a maximum of 64 characters. Any name longer than that will be truncated. The userName buffer is set to "UNKNOWN_USER" if a failure occurs.
* Current ```test``` function can only handle existence of Files and/or Directories

## To Do
* The builtin command ```cd``` has NOT been implemented yet in this version of rshell
* Implement full ```test``` function with flags using a decorator pattern
* Include a way to use the arrow keys for navigation 
* Include a command history, scroll up and down through past commands