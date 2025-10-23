import java_cup . runtime . *;


%%

%class Lexer
%unicode
%line
%column
%cupsym Symbol
%cup
%eofval{
  return symbolFactory.newSymbol ("EOF", Symbol . EOF);
%eofval}

%{
  private SymbolFactory symbolFactory;

  public Lexer (java.io.Reader input, SymbolFactory sf) {
    this (input);
    symbolFactory = sf;
  }

  private void echo () { System . out . print (yytext ()); }

  public int position () { return yycolumn; }
%}

Identifier = [:letter:] ([:letter:] | [:digit:] | [_])*
Integer    = [:digit:] [:digit:]*



%%

[ \t\n]		{ echo (); }
";"		{ echo(); return symbolFactory.newSymbol("(punctuation, ;)",Symbol.SEMICOLON); }
"."		{ echo(); return symbolFactory.newSymbol("(punctuation, .)",Symbol.PERIOD); }
","		{ echo(); return symbolFactory.newSymbol("(punctuation, ,)",Symbol.COMMA); }
"<"		{ echo(); return symbolFactory.newSymbol("(operator, <)",Symbol.LESS_THAN); }
"<="		{ echo(); return symbolFactory.newSymbol("(operator, <=)",Symbol.LESS_THAN_EQUAL); }
">"		{ echo(); return symbolFactory.newSymbol("(operator, >)",Symbol.GREATER_THAN); }
">="		{ echo(); return symbolFactory.newSymbol("(operator, >=)",Symbol.GREATER_THAN_EQUAL); }
"="		{ echo(); return symbolFactory.newSymbol("(operator, =)",Symbol.EQ); }
"=="		{ echo(); return symbolFactory.newSymbol("(operator, ==)",Symbol.EQEQ); }
"!="		{ echo(); return symbolFactory.newSymbol("(operator, !=)",Symbol.NOT_EQ); }
"&&"		{ echo(); return symbolFactory.newSymbol("(operator, &&)",Symbol.AND); }
"||"		{ echo(); return symbolFactory.newSymbol("(operator, ||)",Symbol.OR); }
"!"		{ echo(); return symbolFactory.newSymbol("(operator, !)",Symbol.NOT); }
"+"		{ echo(); return symbolFactory.newSymbol("(operator, +)",Symbol.PLUS); }
"-"		{ echo(); return symbolFactory.newSymbol("(operator, -)",Symbol.MINUS); }
"*"		{ echo(); return symbolFactory.newSymbol("(operator, *)",Symbol.TIMES); }
"/"		{ echo(); return symbolFactory.newSymbol("(operator, /)",Symbol.DIVIDE); }
"("		{ echo(); return symbolFactory.newSymbol("(operator, ()",Symbol.PARENTHESESLEFT); }
")"		{ echo(); return symbolFactory.newSymbol("(operator, ))",Symbol.PARENTHESESRIGHT); }
"{"		{ echo(); return symbolFactory.newSymbol("(punctuation, {)",Symbol.BRACESLEFT); }
"}"		{ echo(); return symbolFactory.newSymbol("(punctuation, })",Symbol.BRACESRIGHT); }
"["		{ echo(); return symbolFactory.newSymbol("(operator, [)",Symbol.BRACKETSLEFT); }
"]"		{ echo(); return symbolFactory.newSymbol("(operator, ])",Symbol.BRACKETSRIGHT); }
while		{ echo(); return symbolFactory.newSymbol("(keyword, while)",Symbol.WHILE);}
import		{ echo(); return symbolFactory.newSymbol("(keyword, import)",Symbol.IMPORT);}
java		{ echo(); return symbolFactory.newSymbol("(keyword, java)",Symbol.JAVA);}
util		{ echo(); return symbolFactory.newSymbol("(keyword, util)",Symbol.UTIL);}
class		{ echo(); return symbolFactory.newSymbol("(keyword, class)",Symbol.CLASS);}
public		{ echo(); return symbolFactory.newSymbol("(keyword, public)",Symbol.PUBLIC);}
static		{ echo(); return symbolFactory.newSymbol("(keyword, static)",Symbol.STATIC);}
void		{ echo(); return symbolFactory.newSymbol("(keyword, void)",Symbol.VOID);}
main		{ echo(); return symbolFactory.newSymbol("(keyword, main)",Symbol.MAIN);}
String		{ echo(); return symbolFactory.newSymbol("(keyword, String)",Symbol.STRING);}
int		{ echo(); return symbolFactory.newSymbol("(keyword, int)",Symbol.INT);}
new		{ echo(); return symbolFactory.newSymbol("(keyword, new)",Symbol.NEW);}
System		{ echo(); return symbolFactory.newSymbol("(keyword, System)",Symbol.SYSTEM);}
out		{ echo(); return symbolFactory.newSymbol("(keyword, out)",Symbol.OUT);}
println		{ echo(); return symbolFactory.newSymbol("(keyword, println)",Symbol.PRINTLN);}
return		{ echo(); return symbolFactory.newSymbol("(keyword, return)",Symbol.RETURN);}
Scanner		{ echo(); return symbolFactory.newSymbol("(keyword, Scanner)",Symbol.SCANNER);}
in		{ echo(); return symbolFactory.newSymbol("(keyword, in)",Symbol.IN);}
args		{ echo(); return symbolFactory.newSymbol("(keyword, args)",Symbol.ARGS);}
nextInt		{ echo(); return symbolFactory.newSymbol("(keyword, nextInt)",Symbol.NEXTINT);}
if		{ echo(); return symbolFactory.newSymbol("(keyword, if)",Symbol.IF);}
else		{ echo(); return symbolFactory.newSymbol("(keyword, else)",Symbol.ELSE);}
this		{ echo(); return symbolFactory.newSymbol("(keyword, this)",Symbol.THIS);}
boolean		{ echo(); return symbolFactory.newSymbol("(keyword, boolean)",Symbol.BOOLEAN);}
{Integer}	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(integer, " + yytext () + ")", 
                      Symbol . INTEGER, yytext ()); }
{Identifier}	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(identifier, " + yytext () + ")", 
                      Symbol . ID, yytext ()); }
.		{ echo (); ErrorMessage . print (yychar, "Illegal character"); }
