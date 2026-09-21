class is a blueprint to make an object , while interface is blueprint to make a class

Interfaces
    - can have abstract methods and static constants (final), unlike abstract classes which can have concrete methods also.

To achieve multiple inheritance and complete abstraction

interfaces can have default methods from java8 -> 
    -  this to add new methods to interfaces without breaking the existing implementation classes
    -  if required these classes can access this method or override 

a class can implement multiple interfaces 

main method can be written in interfaces, as it is static and can be run 

abstract classes can have instance variables and can have constructor to initialize these, while interfaces can't have constructors