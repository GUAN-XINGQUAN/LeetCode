#### Cheating Sheet For Inheritance And Polymorphism (Java)

[TOC]

##### 1. Inheritance

###### 1.0 Parent Class

- You cannot define a method without a body. Otherwise, declare it as an abstract method. 

###### 1.1 Java Abstract Class

- Abstract class can have abstract method and non-abstract method.
- You can instantiate an abstract class - if no abstract method is included in that class. Otherwise, you need to define the abstract methods inside that class when instantiation. 

###### 1.2 Java Interface

- Multiple inheritance is banned in Java. However, this works for interface. 
- All methods inside the interface should be implemented by the "implementing" class.
- You can only define the signature (not the body) in an interface class. An initialized attribute is acceptable inside the interface class. 
- Interface class doesn't contain a constructor. 
- You can cast an implementation of a interface class to that interface object.

##### 2. Polymorphism

###### 2.0 What is polymorphism

Subclasses of a class can define their own unique behaviors and yet share some of the same functionality of the parent class. Source: Oracle. 

###### 2.1 A type casting perspective

- Upcasting is always allowed. Downcasting is banned. Because for non-primitives, typecasting is not really changing an object to another object; it's just referring that target object. 

- As a result, if you refer a subclass to a parent class, then call a method that both exists in the subclass and the parent class, the the call will be re-direct to the subclass's call. Java compiler will firstly check whether the parent class has this method. If the method is inherited by the subclass, that method will be called.  

- However, if you you refer a subclass to a parent class, then call a method that only exists in the subclass - this will report a compiling error, since the parent class doesn't have this method, although the subclass dose. 

  