#Develop, Implement and Execute a program using YACC tool to recognize all strings ending with b preceded by n a’s using the grammar a n b (note: input n value)
####2.l
%{
#include"y.tab.h"
%}
%%
"a" {return A;}
"b" {return B;}
. {return yytext[0];}
\n {return 0;}
%%

#### 2.y
%{
int yywrap();
void yyerror();
int yyparse();
%}
%{
#include<stdio.h>
int valid=1,flag=1,c=0,n;
extern FILE *yyin;
%}
%token A
%token B
%%
S: A S {c++;}
 |B;
%%
void yyerror()
{
  flag=0;
}
int yywrap()
{
  return 1;
}
int main()
{
  printf("enter the value for n:\n");
  scanf("%d",&n);
  yyin=fopen("string.txt","r");
  yyparse();
  if(flag==0 || c!=n)
  {
    printf("invalid string\n");
  }
  if(flag==1 && c==n)
  {
    printf("valid string\n");
  }
}
####string.txt
aaab
