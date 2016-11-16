#!/bin/sh

cd ..
make

bin/rshell << 'DOC'
test bin
test -d bin
test -f bin
test -f main.cpp
exit
DOC

bin/rshell << 'DOC'
[bin]
[-d bin]
[-f bin]
[-f main.cpp]
[ -d src ]
[  -d src  ]
exit
DOC

bin/rshell << 'DOC'
([bin] && test -f header) || echo "hello"
ls || ([asdf]; echo "hello";);
exit
DOC