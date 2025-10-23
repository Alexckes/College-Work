//Declarator.java

public class Declarator {
  public static String id;
  public static Type type;
  public Declarator (String i, Type t) {
    id = i;
    type = t;
  }
  public String Id() {
    return id;
  }
  public Type type() {
    return type;
  }
}