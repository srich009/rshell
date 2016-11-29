#!/bin/sh

cd ..
make
bin/rshell << 'DOC'
ls
exit
DOC

echo

bin/rshell << 'DOC'
pwd
exit
DOC

echo

bin/rshell << 'DOC'
date
exit
DOC


echo

bin/rshell << 'DOC'
vim --version
exit
DOC

echo

bin/rshell << 'DOC'
cd dir
exit
DOC

echo

bin/rshell << 'DOC'
touch thing.txt
ls -a
exit
DOC

echo "hello my name is thing.txt" >> thing.txt

echo

bin/rshell << 'DOC'
cat thing.txt
ls -a
rm -f thing.txt
ls -l
exit
DOC

echo

bin/rshell << 'DOC'
ls -bcdeg
exit
DOC

echo

bin/rshell << 'DOC'
pwd args
exit
DOC

echo

bin/rshell << 'DOC'

exit
DOC

echo

make clean