%{
#include "lexer.h"
#include <QString>
extern int lines;
extern char *yytext;
extern void printError(QString val);
int yyerror(const char* mens)
{
    printError(QString("Error de sintaxis en la linea: %1, en la expresion: %2").arg(lines).arg(yytext));
    return 0;
}
%}


%token START_PROCEDURE 
%token VARIABLE
%token PRINT
%token SCAN
%token VAL_INT
%token VAL_FLOAT 
%token VAL_BOOL 
%token VAL_STRING 
%token INT
%token FLOAT
%token BOOL
%token STRING 
%token ASIGN
%token PLUS
%token MODULE
%token MINUS
%token TIMES 
%token SLASH 
%token INCREMENT 
%token DECREMENT 
%token GREATER 
%token LESS 
%token EQUAL 
%token GREATER_EQUAL
%token LESS_EQUAL 
%token DIFFERENT
%token IF
%token ELSE
%token ELIF 
%token FOR
%token DO
%token WHILE
%token AND
%token OR
%token S_OR
%token S_AND


%start proceso

%%

proceso		: 	START_PROCEDURE '(' ')' '{' lineascodigos '}';
lineascodigos		: 	lineacodigo | ;
lineacodigo		:	lineacodigo linea | linea;
linea			:	crearvariable ';' | cambiarvalor ';' | ciclo_condicion | imprimir ';'| leer ';' | incre_dismin_variable ';';
imprimir 		:	PRINT '(' tipoimprimir ')'| PRINT '(' valor ')' | PRINT '(' VARIABLE ')';
tipoimprimir	: 	valor PLUS tipoimprimir | VARIABLE PLUS tipoimprimir | tipoimprimir PLUS  VARIABLE | valor | VARIABLE;
leer	 		:	SCAN '(' VARIABLE')';
valor				:	VAL_INT | VAL_FLOAT | VAL_BOOL | VAL_STRING;  
crearvariable		:	tipodato VARIABLE | tipodato VARIABLE asignarvalor | tipodato VARIABLE ',' otra_variable | tipodato VARIABLE asignarvalor ',' otra_variable;
otra_variable 		:	VARIABLE | VARIABLE asignarvalor | VARIABLE ',' otra_variable | VARIABLE asignarvalor ',' otra_variable;
tipodato			:	INT | FLOAT | BOOL | STRING;
asignarvalor		:	ASIGN operacion_asignacion | ASIGN valor | ASIGN VARIABLE;
operacion_asignacion	:	aritmetica | incre_dismin_variable;
aritmetica		:	operacion_comun | operacion_comun operacion_complemento;
operacion_comun		:	valor tipo_operacion valor | valor tipo_operacion VARIABLE | VARIABLE tipo_operacion valor | VARIABLE tipo_operacion VARIABLE;
tipo_operacion		:	PLUS | MINUS | TIMES | SLASH | MODULE | condicional;
operacion_complemento	:	operacion_complemento operacion_complemto | operacion_complemto;
operacion_complemto	:	tipo_operacion valor | tipo_operacion VARIABLE;
incre_dismin_variable	:	VARIABLE incre_dismin;
incre_dismin		:	INCREMENT | DECREMENT;
cambiarvalor		:	VARIABLE ASIGN cambio_valor;
cambio_valor		:	valor | operacion_asignacion | VARIABLE;
ciclo_condicion		:	ifcondicion | ciclofor | ciclowhile | ciclodo;
ifcondicion		:	condicion_si | condicion_si condicion_no | condicion_si condiciones_sino condicion_no;
condicion_si		:	IF '(' condicion ')' '{' lineascodigos '}';
condicion		:	operando condicional operando | condicion conector condicion;
operando : valor | aritmetica | VARIABLE | condicion;



conector : AND | OR | S_OR | S_AND;
condicional		:	GREATER | LESS | EQUAL | GREATER_EQUAL | LESS_EQUAL | DIFFERENT;
condicion_no		:	ELSE '{' lineascodigos '}';
condiciones_sino	:	condiciones_sino condicion_sino | condicion_sino;
condicion_sino		:	ELIF '(' condicion ')' '{' lineascodigos '}';
ciclofor		:	FOR '(' inicia_for ';' hasta_for ';' pasos_for ')' '{' lineascodigos '}' | ;
inicia_for		:	tipodato VARIABLE asignarvalor | VARIABLE asignarvalor | ;
hasta_for		: 	condicion | ;
pasos_for		:	incre_dismin_variable | ;
ciclowhile		:	WHILE '(' while_condicion ')' '{' lineascodigos '}';
while_condicion	:	condicion | VAL_BOOL ;
ciclodo 		:	DO '{' lineascodigos '}' WHILE '(' while_condicion ')' ';' ;

%%

void set_input_string(const char* in);
void end_lexical_scan(void);

/* This function parses a string */
int parse_string(const char* in) {
  set_input_string(in);
  int rv = yyparse();
  end_lexical_scan();
  return rv;
}