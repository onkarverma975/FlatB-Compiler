bcc:	parser.tab.c lex.yy.c Classes.cpp visitor.cpp Classes.h visitor.h
	g++ -std=c++11 parser.tab.c lex.yy.c -lfl Classes.cpp visitor.cpp  -o bcc

parser.tab.c: parser.y 
	bison -d parser.y 

parser.tab.h: parser.y
	bison -d parser.y 
	
lex.yy.c: scanner.l parser.tab.h
	flex scanner.l

.PHONY: clean 
clean:
	-@rm -rf parser.tab.c parser.tab.h lex.yy.c bcc 2>/dev/null || true
