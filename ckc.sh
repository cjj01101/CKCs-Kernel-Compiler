#!bash

bison --yacc -v --report-file=./output/y.output --header=./include/y.tab.h -o ./src/y.tab.c ./bison/parser.y -Wcounterexamples
flex -o ./src/lexer.c bison/lexer.l
g++ -I./include -o ckc $(ls ./src |awk '{printf i$0}' i=' ./src/') -lfl -Wno-write-strings