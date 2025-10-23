// Symbol class definition
// Symbol is a class to represent lexical tokens in the PL/0 
// programming language, described in Algorithms + Data
// Structures = Programs by Niklaus Wirth, Prentice-Hall, 1976.

public class Symbol {    // token classes
  public static final int EOF       = -1;
  public static final int BEGIN     =  0;
  public static final int CALL      =  1;
  public static final int CONST     =  2;
  public static final int DO        =  3;
  public static final int END       =  4;
  public static final int IF        =  5;
  public static final int ODD       =  6;
  public static final int PROC      =  7;
  public static final int THEN      =  8;
  public static final int VAR       =  9;
  public static final int WHILE     = 10;
  public static final int ID        = 11;
  public static final int INTEGER   = 12;
  public static final int EQEQ    = 13;
  public static final int AND    = 14;
  public static final int OR    = 15;
  public static final int BRACESLEFT    = '}';
  public static final int BRACESRIGHT    = '{';
  public static final int BRACKETSLEFT    = ']';
  public static final int BRACKETSRIGHT  = '[';
  public static final int IMPORT    = 16;
  public static final int JAVA    = 17;
  public static final int UTIL    = 18;
  public static final int CLASS    = 19;
  public static final int PUBLIC    = 20;
  public static final int STATIC    = 21;
  public static final int VOID    = 22;
  public static final int MAIN    = 23;
  public static final int STRING    = 24;
  public static final int INT    = 25;
  public static final int NEW    = 26;
  public static final int SYSTEM    = 27;
  public static final int OUT    = 28;
  public static final int PRINTLN    = 29;
  public static final int RETURN    = 30;
  public static final int SCANNER    = 31;
  public static final int IN    = 32;
  public static final int ARGS    = 33;
  public static final int NEXTINT    = 34;
  public static final int ELSE    = 35;
  public static final int THIS    = 36;
  public static final int BOOLEAN    = 37;



  public static final int NOT    = '!';
  public static final int PLUS 	    = '+';
  public static final int MINUS     = '-';
  public static final int TIMES     = '*';
  public static final int DIVIDE     = '/';
  public static final int EQ        = '=';
  public static final int LESS_THAN        = '<';
  public static final int GREATER_THAN        = '>';
  public static final int NOT_EQ        = GREATER_THAN + 1;
  public static final int LESS_THAN_EQUAL        = NOT_EQ + 1;
  public static final int GREATER_THAN_EQUAL        = LESS_THAN_EQUAL + 1;
  public static final int PARENTHESESLEFT    = '(';
  public static final int PARENTHESESRIGHT    = ')';
  public static final int COMMA     = ',';
  public static final int PERIOD    = '.';
  public static final int SEMICOLON = ';';
}
