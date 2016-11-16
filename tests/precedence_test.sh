#!/bin/sh

cd ..
make

bin/rshell << 'DOC'
(cd asdf && pwd) || ls
exit
DOC

bin/rshell << 'DOC'
(cd asdf || (date && pwd)) && ls
exit
DOC

bin/rshell << 'DOC'
(ls && (pwd || cd dir)
exit
DOC

bin/rshell << 'DOC'
ls && (cd dir || date)
exit
DOC

bin/rshell << 'DOC'
(((((((echo "asuh dude")))))))
exit
DOC