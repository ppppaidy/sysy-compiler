/* lexer.l */
/* analyse lex */

%{
    #include "globals.h"
    #include "scan.h"
    #include "parser.tab.hpp"
    char tokenString[MAXTOKENLEN+1];
%}

digit                   [0-9]
nonzero_digit           [1-9]
octal_digit             [0-7]
hexdecimal_digit        [0-9a-fA-F]
identifier_nondigit     [_a-zA-Z]
identifier              {identifier_nondigit}({identifier_nondigit}|{digit})*
decimal_const           {nonzero_digit}{digit}*
octal_const             "0"{octal_digit}*
hexdecimal_prefix       "0x"|"0X"
hexdecimal_const        {hexdecimal_prefix}{hexdecimal_digit}+
integer_const           {decimal_const}|{octal_const}|{hexdecimal_const}
whitespace              [ \t\n]
annotation              (\/\/[^\n]*)|(\/\*([^\*^\/]*|[\*^\/*]*|[^\**\/]*)*\*\/)


%%
"if"                    {return IF;}
"else"                  {return ELSE;}
"while"                 {return WHILE;}
"break"                 {return BREAK;}
"continue"              {return CONTINUE;}
"return"                {return RETURN;}
"const"                 {return CONST;}
"int"                   {return INT;}
"void"                  {return VOID;}
"="                     {return ASSIGN;}
"=="                    {return EQ;}
"!="                    {return NEQ;}
"<"                     {return LT;}
">"                     {return GT;}
"<="                    {return LEQ;}
">="                    {return GEQ;}
"+"                     {return ADD;}
"-"                     {return SUB;}
"*"                     {return MUL;}
"/"                     {return DIV;}
"%"                     {return MOD;}
"!"                     {return NOT;}
"&&"                    {return AND;}
"||"                    {return OR;}
"("                     {return LPAREN;}
")"                     {return RPAREN;}
"["                     {return LBRACK;}
"]"                     {return RBRACK;}
"{"                     {return LBPAREN;}
"}"                     {return RBPAREN;}
","                     {return COMMA;}
";"                     {return SEMI;}
{integer_const}         {return NUM;}
{identifier}            {return ID;}
{whitespace}            {}
{annotation}            {}
.                       {return ERROR;}
%%

int getToken(){
    static int firstTime = 1;
    int currentToken;
    if (firstTime){
        firstTime = 0;
        yyin = source;
    }
    currentToken = yylex();
    if(strcmp(yytext, "main") == 0) exit(10);
    if(currentToken != ENDFILE){
        strncpy(tokenString, yytext, MAXTOKENLEN);
        printf("%d %s\n", (int)currentToken, tokenString);
    }
    return currentToken;
}

int yywrap(){
    return 1;
}