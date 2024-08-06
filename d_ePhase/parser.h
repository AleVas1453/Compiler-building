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
    STRING = 261,                  /* "string"  */
    IF = 262,                      /* "if"  */
    ELSE = 263,                    /* "else"  */
    THEN = 264,                    /* "then"  */
    FOR = 265,                     /* "for"  */
    WHILE = 266,                   /* "while"  */
    BREAK = 267,                   /* "break"  */
    CONTINUE = 268,                /* "continue"  */
    RETURN = 269,                  /* "return"  */
    TRUE = 270,                    /* "true"  */
    FALSE = 271,                   /* "false"  */
    NOT = 272,                     /* "not"  */
    AND = 273,                     /* "and"  */
    OR = 274,                      /* "or"  */
    FUNCTION = 275,                /* "function"  */
    NIL = 276,                     /* "nil"  */
    SIMPLESPACE = 277,             /* "simplespace"  */
    NEWLINE = 278,                 /* "newline"  */
    MULTISPACE = 279,              /* "multispace"  */
    LINECOMMENT = 280,             /* "linecomment"  */
    LEFTBRACKET = 281,             /* "["  */
    RIGHTBRACKET = 282,            /* "]"  */
    LEFTPARENTHESES = 283,         /* "("  */
    RIGHTPARENTHESES = 284,        /* ")"  */
    LEFTBRACES = 285,              /* "{"  */
    RIGHTBRACES = 286,             /* "}"  */
    COLON = 287,                   /* ":"  */
    SEMICOLON = 288,               /* ";"  */
    COMMA = 289,                   /* ","  */
    FULLSTOP = 290,                /* "."  */
    DFULLSTOP = 291,               /* ".."  */
    PLUS = 292,                    /* "+"  */
    SUB = 293,                     /* "-"  */
    MULTIPLY = 294,                /* "*"  */
    DIVISION = 295,                /* "/"  */
    PERCENT = 296,                 /* "%"  */
    PLUSPLUS = 297,                /* "++"  */
    MINUSMINUS = 298,              /* "--"  */
    EQUAL = 299,                   /* "="  */
    NOTEQUAL = 300,                /* "!="  */
    GREATER = 301,                 /* ">"  */
    LESS = 302,                    /* "<"  */
    LESSEQUAL = 303,               /* "<="  */
    GREATEREQUAL = 304,            /* ">="  */
    EQUALEQUAL = 305,              /* "=="  */
    SCOPERESOLUTION = 306,         /* "::"  */
    LOCAL = 307,                   /* LOCAL  */
    UMINUS = 308                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "parser.y"

    char* stringValue;
    int intValue;
    double doubValue;
    struct expr* exprValue;
    struct symbol* symValue;
    struct call_l* callValue;
    struct for_t* forValue;
    struct list_t* listValue;
    struct stmt_t* stmtValue;

#line 129 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
