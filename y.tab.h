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
     TK_FLOAT = 259,
     TK_SCIENTIFIC = 260,
     TK_CHAR = 261,
     TK_STRING = 262,
     TK_BOOL = 263,
     TK_TRUE = 264,
     TK_FALSE = 265,
     TK_MAIN = 266,
     TK_ID = 267,
     TK_TYPE_CHAR = 268,
     TK_TYPE_STRING = 269,
     TK_TYPE_INT = 270,
     TK_TYPE_VOID = 271,
     TK_TYPE_FLOAT = 272,
     TK_TYPE_DOUBLE = 273,
     TK_TYPE_BOOL = 274,
     TK_MODIFIER_UNSIGNED = 275,
     TK_MODIFIER_SIGNED = 276,
     TK_MODIFIER_SHORT = 277,
     TK_MODIFIER_LONG = 278,
     TK_END = 279,
     TK_ERROR = 280,
     TK_OP_SUM = 281,
     TK_OP_SUB = 282,
     TK_OP_MUL = 283,
     TK_OP_DIV = 284,
     TK_OP_REL_LESS = 285,
     TK_OP_REL_GREATER = 286,
     TK_OP_REL_EQLESS = 287,
     TK_OP_REL_EQGREATER = 288,
     TK_OP_REL_EQ = 289,
     TK_OP_REL_DIFF = 290,
     TK_OP_LOGIC_AND = 291,
     TK_OP_LOGIC_OR = 292,
     TK_OP_LOGIC_NOT = 293,
     TK_OP_BIN_AND = 294,
     TK_OP_BIN_OR = 295,
     TK_OP_BIN_XOR = 296,
     TK_OP_BIN_NOT = 297,
     TK_OP_BIN_SHIFTR = 298,
     TK_OP_BIN_SHIFTL = 299,
     TK_ASSIGN = 300,
     TK_RETURN = 301,
     TK_OP_MOD = 302
   };
#endif
/* Tokens.  */
#define TK_INT 258
#define TK_FLOAT 259
#define TK_SCIENTIFIC 260
#define TK_CHAR 261
#define TK_STRING 262
#define TK_BOOL 263
#define TK_TRUE 264
#define TK_FALSE 265
#define TK_MAIN 266
#define TK_ID 267
#define TK_TYPE_CHAR 268
#define TK_TYPE_STRING 269
#define TK_TYPE_INT 270
#define TK_TYPE_VOID 271
#define TK_TYPE_FLOAT 272
#define TK_TYPE_DOUBLE 273
#define TK_TYPE_BOOL 274
#define TK_MODIFIER_UNSIGNED 275
#define TK_MODIFIER_SIGNED 276
#define TK_MODIFIER_SHORT 277
#define TK_MODIFIER_LONG 278
#define TK_END 279
#define TK_ERROR 280
#define TK_OP_SUM 281
#define TK_OP_SUB 282
#define TK_OP_MUL 283
#define TK_OP_DIV 284
#define TK_OP_REL_LESS 285
#define TK_OP_REL_GREATER 286
#define TK_OP_REL_EQLESS 287
#define TK_OP_REL_EQGREATER 288
#define TK_OP_REL_EQ 289
#define TK_OP_REL_DIFF 290
#define TK_OP_LOGIC_AND 291
#define TK_OP_LOGIC_OR 292
#define TK_OP_LOGIC_NOT 293
#define TK_OP_BIN_AND 294
#define TK_OP_BIN_OR 295
#define TK_OP_BIN_XOR 296
#define TK_OP_BIN_NOT 297
#define TK_OP_BIN_SHIFTR 298
#define TK_OP_BIN_SHIFTL 299
#define TK_ASSIGN 300
#define TK_RETURN 301
#define TK_OP_MOD 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


