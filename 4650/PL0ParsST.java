// PL0ParsST.java

// This program is a parser for PL/0 which contsructs the symbol table from
// the source program declarations.

import java_cup . runtime . *;
import java.io.*;

public class PL0ParsST {

  public static void main (String args []) throws IOException {
    System . out . println ("Source Program");
    System . out . println ("--------------");
    System . out . println ();

    try {
      SymbolFactory symbolFactory = new ComplexSymbolFactory ();
      PL0ParserST parser = new PL0ParserST (new PL0Lexer (new InputStreamReader (System . in), symbolFactory), symbolFactory);
      java_cup .runtime . Symbol parserValue = parser . parse ();
      SymbolTable env = (SymbolTable) parserValue . value;
      env . print ("main");
    }
    catch (Exception e) {
      System . out . println ("Error in invoking parser/lexer");
    }
  }

}
