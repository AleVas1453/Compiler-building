/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* "id"  */
    INT = 259,                     /* "int"  */
    DOUBLE = 260,                  /* "double"  */
    IF = 261,                      /* "if"  */
    ELSE = 262,                    /* "else"  */
    THEN = 263,                    /* "then"  */
    FOR = 264,                     /* "for"  */
    WHILE = 265,                   /* "while"  */
    BREAK = 266,                   /* "break"  */
    CONTINUE = 267,                /* "continue"  */
    RETURN = 268,                  /* "return"  */
    TRUE = 269,                    /* "true"  */
    FALSE = 270,                   /* "false"  */
    NOT = 271,                     /* "not"  */
    AND = 272,                     /* "and"  */
    OR = 273,                      /* "or"  */
    FUNCTION = 274,                /* "function"  */
    NIL = 275,                     /* "nil"  */
    SIMPLESPACE = 276,             /* "simplespace"  */
    NEWLINE = 277,                 /* "newline"  */
    MULTISPACE = 278,              /* "multispace"  */
    LINECOMMENT = 279,             /* "linecomment"  */
    LEFTBRACKET = 280,             /* "["  */
    RIGHTBRACKET = 281,            /* "]"  */
    LEFTPARENTHESES = 282,         /* "("  */
    RIGHTPARENTHESES = 283,        /* ")"  */
    LEFTBRACES = 284,              /* "{"  */
    RIGHTBRACES = 285,             /* "}"  */
    COLON = 286,                   /* ":"  */
    SEMICOLON = 287,               /* ";"  */
    COMMA = 288,                   /* ","  */
    FULLSTOP = 289,                /* "."  */
    DFULLSTOP = 290,               /* ".."  */
    PLUS = 291,                    /* "+"  */
    SUB = 292,                     /* "-"  */
    MULTIPLY = 293,                /* "*"  */
    DIVISION = 294,                /* "/"  */
    PERCENT = 295,                 /* "%"  */
    PLUSPLUS = 296,                /* "++"  */
    MINUSMINUS = 297,              /* "--"  */
    EQUAL = 298,                   /* "="  */
    NOTEQUAL = 299,                /* "!="  */
    GREATER = 300,                 /* ">"  */
    LESS = 301,                    /* "<"  */
    LESSEQUAL = 302,               /* "<="  */
    GREATEREQUAL = 303,            /* ">="  */
    EQUALEQUAL = 304,              /* "=="  */
    SCOPERESOLUTION = 305,         /* "::"  */
    LOCALY = 306,                  /* LOCALY  */
    UMINUS = 307                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "parser.y"

    char* stringValue;
    int intValue;
    double doubValue;

#line 122 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
