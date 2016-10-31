# rshell
UCR CS100 Open Source Shell Project

##### Authors:
* Sean Richardson - https://github.com/srich009
* Krishna Pakalapati - https://github.com/KrishnaP7

## Introduction
This program is a working subset of Linux BASH that supports basic commands. 

## Installation
Run these commands in your terminal to install and run rshell on your system
```Installation
$ git clone https://github.com/srich009/rshell.git

$ cd rshell

$ make

$ bin/rshell
```

## Bugs
* The host name obtained by ```gethostname()``` is limited to a maximum of 64 characters. Any name longer than that will be truncated.
* ```getlogin_r()``` appears be used in conformance to The Linux Programmer's Manual and UNIX ® Specification, but usually fails and message ```"getLogin_r(): No such process"``` is printed. The userName buffer is set to "UNKNOWN" on failure.
