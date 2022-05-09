#!bash

CXXFLAGS="-D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -I./include -I./llvm/include -Wno-write-strings"
LDFLAGS="-L./llvm/lib -lLLVM -lfl"

echo "Start Bison compiling..."

bison --yacc -v --report-file=./output/y.output --header=./include/y.tab.h -o ./src/y.tab.c ./bison/parser.y -Wcounterexamples
flex -o ./src/lexer.c bison/lexer.l

echo "Start GCC/G++ compiling..."

g++ -o ckc $(ls ./src |awk '{printf i$0}' i=' ./src/') ${CXXFLAGS} ${LDFLAGS}