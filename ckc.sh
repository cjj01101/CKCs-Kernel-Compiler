#!bash

bison --yacc -dv parser.y
flex lexer.l
g++ -o ckc main.cpp y.tab.c lex.yy.c Node.cpp -lfl