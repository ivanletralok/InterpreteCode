%option noyywrap
%{
#include "parser.h"
#include <QString>
#include <QPlainTextEdit>
int lines =1;
int errorLine = 1;
QPlainTextEdit* error;
int errorLineNumber(){
       return errorLine;
};

void setTextEditError(QPlainTextEdit* edit1)   {
    lines=1;
    error=edit1;
}

void printError(QString val){
    error->appendPlainText(val);
    errorLine=lines;
}
%}

ignore " "|\t|\r
character [A-Za-z]
digit [0-9]
boolean "code.true"|"code.false"

%%

{ignore}							{;}
"\n"								{lines++;}
"."									{return ('.');}
"{"									{return ('{');}
"}"									{return ('}');}
";"									{return (';');}
","									{return (',');}
"("									{return ('(');}
")"									{return (')');}
"["									{return ('[');}
"]"									{return (']');}
"code.if"							{return IF;}
"code.elif"							{return ELIF;}
"code.else"							{return ELSE;}
"start procedure"					{return START_PROCEDURE;}
"code.int"							{return INT;}
"code.float"						{return FLOAT;}
"code.bool"							{return BOOL;}
"code.string"						{return STRING;}
"code.for"							{return FOR;}
"code.while"						{return WHILE;}
"code.print"						{return PRINT;}
"code.scan"							{return SCAN;}
"code.do"							{return DO;}
"+"									{return PLUS;}
"-"									{return MINUS;}
"*"									{return TIMES;}
"%"									{return MODULE;}
"/"									{return SLASH;}
"++"								{return INCREMENT;}
"--"								{return DECREMENT;}
"="									{return ASIGN;}
">"									{return GREATER;}
"<"									{return LESS;}
"=="								{return EQUAL;}
">="								{return GREATER_EQUAL;}
"<="								{return LESS_EQUAL;}
"&&"								{return AND;}
"||"								{return OR;}
"and"								{return S_AND;}
"or"								{return S_OR;}
"!="								{return DIFFERENT;}
{digit}+							{return VAL_INT;}
{digit}+"."{digit}+					{return VAL_FLOAT;}
{boolean}							{return VAL_BOOL;}
"\""({digit}|{character}|" ")*"\""	{return VAL_STRING;}
{character}({character}|(digito))*	{return VARIABLE;}
.					{printError(QString("Error en la linea %1, expresion: \"%2\"").arg(lines).arg(yytext)); }

%%

void set_input_string(const char* in) {
  yy_scan_string(in);
}

void end_lexical_scan(void) {
  yy_delete_buffer(YY_CURRENT_BUFFER);
}
