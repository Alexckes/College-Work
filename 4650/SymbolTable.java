// SymbolTable.java

import java.util.*;

enum Category {CLASS, FUNCTION, VARIABLE}

class Type { 

public String toCode1() {return "";}

public String toCode2() {return "";}

public int dimension() {return 0;}

}

// IntegerType represents the type of integer variables in TinyJava.

class IntegerType extends Type {

  public String toString () {
    return "int";
  }

  @Override public String toCode1() {return "int";}

  @Override public String toCode2() {return "";}

}

// BooleanType represents the type of Boolean variables in TinyJava.

class BooleanType extends Type {

  public String toString () {
    return "boolean";
  }

  @Override public String toCode1() {return "int";}

  @Override public String toCode2() {return "";}

}

// VoidType represents the type of void variables in TinyJava.

class VoidType extends Type {

  public String toString () {
    return "void";
  }

  @Override public String toCode1() {return "void";}

  @Override public String toCode2() {return "";}

}

// ArrayType represents array types in TinyJava.

class ArrayType extends Type {

  private int dimension;
  private Type baseType;

  public ArrayType (int dim, Type base) {
    dimension = dim;
    baseType = base;
  }

  @Override public int dimension () { return dimension; }

  public String toString () {
    return "array (" + dimension + ", " + baseType + ")";
  }

  @Override public String toCode1 () {return baseType.toCode1() + "*";}

  @Override public String toCode2 () {
    return " [" + dimension + "]";
  }

}

// ObjectType represents object types in TinyJava.

class ObjectType extends Type {

  private String className;
  private SymbolTableEntry objectType;

  public ObjectType (String className, SymbolTableEntry objectType) {
    this . className = className;
    this . objectType = objectType;
  }

  public String className () { return className; }

  public SymbolTableEntry objectType () { return objectType; }

  public String toString () {
    return className;
  }

  @Override public String toCode1() {return className;}

  @Override public String toCode2() {return "";}

}

// Declarator is a class which defines an identifier and its type.

class Declarator {

  private String id;
  private Type type;

  public Declarator (String id, Type type) {
    this . id = id;
    this . type = type;
  }

  public String id () { return id; }

  public Type type () { return type; }

}

// ArrayDeclarator is a class which defines arrays.

class ArrayDeclarator extends Declarator {

  private int subscriptNumber;

  public ArrayDeclarator (String id, Type type, int subscriptNumber) {
    super (id, type);
    this . subscriptNumber = subscriptNumber;
  }

  public int subscriptNumber () { return subscriptNumber; }

}

// SymbolTableEntry is a class to represent the symbol table entries
// for TinyJava programs.

class SymbolTableEntry {

  private Category category;
  private boolean staticFlag;
  private Type type;
  private LinkedList<Type> argTypes;
  private SymbolTable localEnv;
  private String funcCode;

  public SymbolTableEntry (Category category) { 
    this . category = category;
  }

  public SymbolTableEntry (Category category, Type type) {
    this . category = category;
    this . type = type;
  }

  public SymbolTableEntry (Category category, Type type, boolean staticFlag) {
    this . category = category;
    this . type = type;
    this . staticFlag = staticFlag;
  }

  public SymbolTableEntry (Category category, SymbolTable env) {
    this . category = category;
    this . localEnv = env;
  }

  public SymbolTableEntry (Category category, Type type, boolean staticFlag,
      LinkedList<Type> argTypes, SymbolTable env) {
    this . category = category;
    this . type = type;
    this . staticFlag = staticFlag;
    this . argTypes = argTypes;
    this . localEnv = env;
  }

  public Category category () { return category; }

  public boolean staticFlag () { return staticFlag; }

  public Type type () { return type; }

  public SymbolTable localEnv () { return localEnv; }

  public String funcCode () { return funcCode; }

  public void setType ( Type t ) {type = t;}

  public void setCode (String code) { funcCode = code; }

  public String toString () {
    String printString = category . name ();
    if (category == Category . VARIABLE || category == Category . FUNCTION) {
      if (staticFlag)
        printString = printString + " yes   ";
      else
        printString = printString + " no    ";
      if (category == Category . VARIABLE)
        printString = printString + " " + type;
      else
        printString = printString + " " + argTypes + "->" + type;
    }
    return printString;
  }

}
 
// SymbolTable is a class to represent the symbol table for TinyJava programs.

public class SymbolTable {

  private static int maxlen = 2; // for header "Id"

  public static int maxLen () { return maxlen; }

  private SymbolTable parent;				// static parent

  private TreeMap <String, SymbolTableEntry> table; 	// id table

  public SymbolTable (SymbolTable staticParent) { 
    parent = staticParent;
    table = new TreeMap <String, SymbolTableEntry> (); 
  }

  public SymbolTable parent () { return parent; }

  // The entry function returns the symbol table entry for the id, including
  // if the id appears in a parent's symbol table. If the id has not been 
  // declared, it prints an appropriate error message.

  public SymbolTableEntry entry (String id) {
    SymbolTableEntry idEntry = table . get (id);
    if (idEntry == null)
      if (parent == null)
        ErrorMessage . print ("Undeclared identifier: " + id);
      else				// not found in this scope
        idEntry = parent . entry (id); 	// check parent
    return idEntry;
  }

  public boolean hasEntry (String id) {
	return table.containsKey(id);
  }

  // The enter function enters an id and its information into the symbol
  // table.

  public void enter (String id, SymbolTableEntry entry) {
    SymbolTableEntry idEntry = table . get (id);
    if (idEntry != null)
      ErrorMessage . print ("Identifier " + id + " already declared.");
    table . put (id, entry);
    if (id . length () > maxlen)
      maxlen = id . length ();
  }

  // The enterVar function enters a variable id into the symbol table.
 
  public void enterVar (String id, Type type) { 
    enter (id, new SymbolTableEntry (Category . VARIABLE, type));
  }

  public void enterVar (String id, Type type, boolean staticFlag) { 
    enter (id, new SymbolTableEntry (Category . VARIABLE, type, staticFlag));
  }

  // The enterFunc function enters a function id, its return type and its local 
  // symbol table into the symbol table. When this function is called, the local
  // symbol table contains only the formal parameters. This entry is needed to
  // allow type checking of recursive calls.

  public void enterFunc (String id, Type type, boolean staticFlag,
      LinkedList<Type> argTypes, SymbolTable env) {
    enter (id, new SymbolTableEntry (Category . FUNCTION, type, staticFlag,
      argTypes, env));
  }

  // The enterFuncCode function enters the code for function id into the
  // symbol table. The entry for id has already been added by enterFunc.

  public void enterFuncCode (String id, String code) {
    SymbolTableEntry idEntry = table . get (id);
    idEntry . setCode (code);
  }

  // The enterClass function enters a class id and its local symbol table 
  // into the symbol table.

  public void enterClass (String id, SymbolTable env) {
    enter (id, new SymbolTableEntry (Category . CLASS, env));
  }

  public void editVarType(String id,Type type){
    SymbolTableEntry idEntry = table . get (id);
    idEntry . setType(type);
  }

  // The code function generates the code for the symbol table.

  
  // The print function prints the entire symbol table, including local
  // symbol tables for classes and functions.

  public void print (String blockName) {
    System . out . println ();
    System . out . println ("Identifier Table for " + blockName);
    System . out . print ("---------------------");
    for (int i = 0; i < blockName . length (); i++) 
      System . out . print ("-");
    System . out . println ();
    System . out . println ();
    System . out . print ("Id");
    for (int i = 2; i < maxLen (); i++)
      System . out . print (" ");
    System . out . println (" Category Static Type");
    System . out . print ("--");
    for (int i = 2; i < maxLen (); i++)
      System . out . print (" ");
    System . out . println (" -------- ------ ----");
    Iterator <Map . Entry <String, SymbolTableEntry>> envIterator = 
      table . entrySet () . iterator ();
    TreeMap <String, SymbolTableEntry> classAndFunctionList = 
      new TreeMap <String, SymbolTableEntry> ();
    while (envIterator . hasNext ()) {
      Map . Entry <String, SymbolTableEntry> entry = envIterator . next ();
      String id = entry . getKey ();
      SymbolTableEntry idEntry = entry . getValue ();
      System . out . print (id);
      for (int i = id . length (); i < maxLen (); i++)
        System . out . print (" ");
      System . out . print (" ");
      System . out . println (idEntry);
      if (idEntry . category () == Category . CLASS 
          || idEntry . category () == Category . FUNCTION)
        classAndFunctionList . put (id, idEntry);
    }
    Iterator <Map . Entry <String, SymbolTableEntry>> classAndFunctionIterator =
      classAndFunctionList . entrySet () . iterator ();
    while (classAndFunctionIterator . hasNext ()) {
      Map . Entry <String, SymbolTableEntry> entry = 
        classAndFunctionIterator . next ();
      String classOrFunctionName = entry . getKey ();
      SymbolTableEntry idEntry = entry . getValue ();
      idEntry . localEnv () . print (classOrFunctionName);
    }
  }

}
