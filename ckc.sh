#!bash

bison --yacc -v --report-file=./output/y.output --header=./include/y.tab.h -o ./src/y.tab.c ./bison/parser.y  -Wcounterexamples
flex -o ./src/lexer.c bison/lexer.l
cd src
g++ -I../include -o ../ckc main.cpp y.tab.c lexer.c Node.cpp OperatorNode.cpp ValueNode.cpp StatementNode.cpp -lfl -Wno-write-strings