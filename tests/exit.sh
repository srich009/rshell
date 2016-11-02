#!/bin/sh

cd ..
make
bin/rshell << 'DOC'
exit
DOC

bin/rshell << 'DOC'
ls && exit
DOC

bin/rshell << 'DOC'
ls || exit
exit
DOC

bin/rshell << 'DOC'
pwd && date #exit
ls
exit
DOC

echo

make clean