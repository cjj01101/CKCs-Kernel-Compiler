#!bash

FLAGS="-D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -I./include -I./llvm/include"

bison --yacc -v --report-file=./output/y.output --header=./include/y.tab.h -o ./src/y.tab.c ./bison/parser.y -Wcounterexamples
flex -o ./src/lexer.c bison/lexer.l
g++ -o ckc $(ls ./src |awk '{printf i$0}' i=' ./src/') -L./llvm/lib -l:libLLVM.so ${FLAGS} -lfl -Wno-write-strings