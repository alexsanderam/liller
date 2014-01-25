all: 	
		clear
		lex lexica.l
		yacc -v sintatica.y
		g++ -o glf y.tab.c -lfl -std=c++0x

		./glf < exemplo.ll > out.c
		g++ -o out out.c
		./out
