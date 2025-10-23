// ExpressionCode.java

import java.util.*;

// ExpressionCode is a class to represent the intermediate code and 
// variable assignment for TinyJava expressions.

public class ExpressionCode {

  private String code;
  private String place;

  public ExpressionCode (String code, String place) {
    this . code = code;
    this . place = place;
  }

  public String code () { return code; }

  public String place () { return place; }

}
