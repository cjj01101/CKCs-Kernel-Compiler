#!bash

bison --yacc -dv -Wcounterexamples parser.y
flex lexer.l
g++ -o ckc main.cpp y.tab.c lex.yy.c Node.cpp ValueNode.cpp StatementNode.cpp -lfl -Wno-write-strings