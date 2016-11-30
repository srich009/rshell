#!/bin/sh

cd ..
make
bin/rshell << 'DOC'
ls && pwd || date

echo "new" && echo "test"

touch thing.txt && ls -l && rm thing.txt -f && ls -a;

exit

DOC

echo

bin/rshell << 'DOC'
cd dir || echo "tried to echo to non existant directory (OR)"
exit
DOC

echo

bin/rshell << 'DOC'
cd dir; echo "tried to echo to non existant directory (SEMICOLON)"
exit
DOC

echo

bin/rshell << 'DOC'
ls || echo "this SHOULD NOT be printed" && echo "this SHOULD be printed"
exit
DOC

echo

bin/rshell << 'DOC'
cd dir && echo "this SHOULD NOT be printed" && echo "this SHOULD also not be printed" ; echo "this SHOULD be printed"
exit
DOC

echo

bin/rshell << 'DOC'
echo"will this print?" && echo "it did print" || echo "it didn't print"
exit
DOC

echo

make clean