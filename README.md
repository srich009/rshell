# rshell
UCR CS100 Open Source Shell

##### Authors:
* Sean Richardson - https://github.com/srich009
* Krishna Pakalapati - https://github.com/KrishnaP7

## Introduction
This project is a small working subset of Linux BASH that supports basic commands and connectors.
This version of rshell supports test functionality in both forms:
* ```test <value>```
* ```[<value>]```

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
* The builtin command ```cd``` has NOT been implemented yet in this version of rshell (hw3)
* The host name obtained by ```gethostname()``` is limited to a maximum of 64 characters. Any name longer than that will be truncated. The hostName buffer is set to "UNKNOWN_HOST" if a failure occurs.
* The user name obtained by ```gelogin_r()``` is limited to a maximum of 64 characters. Any name longer than that will be truncated. The userName buffer is set to "UNKNOWN_USER" if a failure occurs.
* If the user enters improperly formatted command line arguments leading with a connector, erroneous behavior may occur
    * ```user@host$ && ls``` will not execute ls
    * ```user@host$ || ls``` will execute ls
    * ```user@host$ ; ls``` errors will most likely occur
