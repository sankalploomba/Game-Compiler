%{
#include <string>
#include <stdio.h>
using namespace std;
#include "mylang.tab.hh"
void yyerror(char *);
int yyparse(void);
%}
%%

";"		return SEMICOLON;
[ \t\n]+		; //do nothing on white space
(W|w)		{yylval.int_val = UP; return MOV;}
(A|a)		{yylval.int_val = LEFT; return MOV;}
(S|s)		{yylval.int_val = DOWN; return MOV;}
(D|d)		{yylval.int_val = RIGHT; return MOV;}
(P|p)		{return PAUSE;}
(Q|q)		{return QUIT;}
.			printf("Unexpected Character\n");
%%

void yyerror(char *str)
{
	printf("Parse Error: \n%s\n",str);
}

int yywrap(void)
{
	return 1;
}

int main()
{
	yyparse();
}



