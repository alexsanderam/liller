/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
     TK_INT = 258,
     TK_MAIN = 259,
     TK_ID = 260,
     TK_TYPE_INT = 261,
     TK_TYPE_VOID = 262,
     TK_END = 263,
     TK_ERROR = 264,
     TK_OP_SUM = 265,
     TK_OP_SUB = 266,
     TK_OP_MUL = 267,
     TK_OP_DIV = 268,
     TK_ASSIGN = 269,
     TK_OP_MOD = 270
   };
#endif
/* Tokens.  */
#define TK_INT 258
#define TK_MAIN 259
#define TK_ID 260
#define TK_TYPE_INT 261
#define TK_TYPE_VOID 262
#define TK_END 263
#define TK_ERROR 264
#define TK_OP_SUM 265
#define TK_OP_SUB 266
#define TK_OP_MUL 267
#define TK_OP_DIV 268
#define TK_ASSIGN 269
#define TK_OP_MOD 270




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


