
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
     TK_INT = 258,
     TK_FLOAT = 259,
     TK_SCIENTIFIC = 260,
     TK_CHAR = 261,
     TK_MAIN = 262,
     TK_ID = 263,
     TK_TYPE_CHAR = 264,
     TK_TYPE_STRING = 265,
     TK_TYPE_INT = 266,
     TK_TYPE_VOID = 267,
     TK_TYPE_FLOAT = 268,
     TK_TYPE_DOUBLE = 269,
     TK_TYPE_UNSIGNED = 270,
     TK_TYPE_LONG = 271,
     TK_TYPE_BOOLEAN = 272,
     TK_END = 273,
     TK_ERROR = 274,
     TK_OP_SUM = 275,
     TK_OP_SUB = 276,
     TK_OP_MUL = 277,
     TK_OP_DIV = 278,
     TK_ASSIGN = 279,
     TK_OP_MOD = 280
   };
#endif
/* Tokens.  */
#define TK_INT 258
#define TK_FLOAT 259
#define TK_SCIENTIFIC 260
#define TK_CHAR 261
#define TK_MAIN 262
#define TK_ID 263
#define TK_TYPE_CHAR 264
#define TK_TYPE_STRING 265
#define TK_TYPE_INT 266
#define TK_TYPE_VOID 267
#define TK_TYPE_FLOAT 268
#define TK_TYPE_DOUBLE 269
#define TK_TYPE_UNSIGNED 270
#define TK_TYPE_LONG 271
#define TK_TYPE_BOOLEAN 272
#define TK_END 273
#define TK_ERROR 274
#define TK_OP_SUM 275
#define TK_OP_SUB 276
#define TK_OP_MUL 277
#define TK_OP_DIV 278
#define TK_ASSIGN 279
#define TK_OP_MOD 280




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


