#ifndef PARSER_H
#define PARSER_H


/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     START_PROCEDURE = 258,
     VARIABLE = 259,
     PRINT = 260,
     SCAN = 261,
     VAL_INT = 262,
     VAL_FLOAT = 263,
     VAL_BOOL = 264,
     VAL_STRING = 265,
     INT = 266,
     FLOAT = 267,
     BOOL = 268,
     STRING = 269,
     ASIGN = 270,
     PLUS = 271,
     MODULE = 272,
     MINUS = 273,
     TIMES = 274,
     SLASH = 275,
     INCREMENT = 276,
     DECREMENT = 277,
     GREATER = 278,
     LESS = 279,
     EQUAL = 280,
     GREATER_EQUAL = 281,
     LESS_EQUAL = 282,
     DIFFERENT = 283,
     IF = 284,
     ELSE = 285,
     ELIF = 286,
     FOR = 287,
     DO = 288,
     WHILE = 289,
     AND = 290,
     OR = 291,
     S_OR = 292,
     S_AND = 293
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



#endif //PARSER_H
