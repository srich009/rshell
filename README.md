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

The ```test``` command can be used with these flags, if no flag is found, the ```-e``` flag is assumed
* ```-e``` checks if the file/directory exists
* ```-f``` checks if the file/directory exists and is a regular file
* ```-d``` checks if the file/directory exists and is a directory

This version of rshell supports ```cd``` with forms:
* ```cd <PATH>``` will change the current working directory to ```<PATH>```
* ```cd``` will change the current working directory to the user's home directory
* ```cd -``` will change the current working directory to the previous working directory

## Installation
Run these commands in your terminal to install and run rshell on your system
```Installation
$ git clone https://github.com/srich009/rshell.git

$ cd rshell

$ git checkout hw4

$ make

$ bin/rshell
```

## Limitations
* The host name obtained by ```gethostname()``` is limited to a maximum of 64 characters. Any name longer than that will be truncated. The hostName buffer is set to "UNKNOWN_HOST" if an error occurs.
* The user name obtained by ```getlogin_r()``` is limited to a maximum of 64 characters. Any name longer than that will be truncated. The userName buffer is set to "UNKNOWN_USER" if an error occurs.
* The directory name obtained through ```get_current_dir_name()``` is set to the environment variable ```PWD```. The current directory buffer is set to "UNKNOWN_DIR" if an error occurs.
* Current ```test``` function can only handle existence of Files and/or Directories.

## To Do
* Implement I/O redirection
* Implement command piping
* Implement full ```test``` function (Decorator Pattern)
* Include a way to use the arrow keys for navigation 
* Include a command history, scroll up and down through past commands

## Bugs
* If the user enters an argument leading with a connector, an error message is printed.
* If the user enters empty parentheses ```"()"``` OR no argument to act on, an error message is printed.
* If the user enters an empty test case ```"[]"``` OR ```"test"``` followed by no arguments, an execution error occurs, a message is printed.
* PARSE ERRORS WITH "()" && PRECEDENCE
    * ```()()```
    * ```(ls) && pwd```
    * ```ls && (pwd) && echo test```
    * ``` pwd && ((ls) && vim -h)```