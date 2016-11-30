#!/bin/sh
cd ..
make

bin/rshell << 'DOC' #tests cd failure if asdfasdf directory does not exist
test asdfasdf || cd asdfasdf
pwd
exit
DOC

echo

bin/rshell << 'DOC' #tests cd - and whether or not it goes to previous working directory
cd src
pwd
cd ../header
pwd
cd -
pwd
cd -
pwd
exit
DOC

echo

bin/rshell << 'DOC' #tests whether or not it goes to HOME
cd || echo "didn't work"
pwd
exit
DOC

echo

bin/rshell << 'DOC' #cd with multi commands
(cd header && echo "changed directories to header") || echo "failed to change directories to header"
pwd
exit
DOC

echo

make clean