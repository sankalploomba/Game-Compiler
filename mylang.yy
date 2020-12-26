%{
#include "mylang (3 obj).h"
using namespace std;
extern int yylex();
extern void yyerror(char*);
Display d;
%}


%union
{
 int 		int_val;
}

%token <int_val> UP LEFT RIGHT DOWN MOV SEMICOLON PAUSE QUIT
%start parsetree

%%

parsetree:	lines;
lines: lines line | line;
line: 	MOV	
		{
			switch($1)
			{
				case UP: { d.movUp();  break;} 
				case DOWN: { d.movDown(); break;}
				case LEFT: { d.movLeft(); break;}
				case RIGHT: { d.movRight(); break;}	
				default: printf("%d\n",$1);	
			}
		};
		
		| PAUSE {d.pause();};
		| QUIT  {system("clear");	exit(0);};

%%
