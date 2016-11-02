#!/bin/sh

cd ..
make
bin/rshell << 'DOC'
ls #pwd
exit
DOC

echo

bin/rshell << 'DOC'
#exit
pwd
exit
DOC

echo

bin/rshell << 'DOC'
echo "the last word of this sentence should be" #truncated # "truncated"
exit
DOC

make clean
