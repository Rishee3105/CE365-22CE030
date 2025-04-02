%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

\+91-[0-9]{10}   { printf("Valid Phone Number: %s\n", yytext); } 
\+91[ ][0-9]{10} { printf("Valid Phone Number: %s\n", yytext); }  
[0-9]{10}        { printf("Valid Phone Number: %s\n", yytext); }  
.|\n             { printf("Invalid phone Number:%s\n",yytext);}                  
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
