hiding the implementation details 

if we want to give a method signature but doesn't want to implementation 

a method without method definition is called abstract method
    - an abstract method should be declared in a abstract class , 
    - but an abstract class can have concrete methods 

methods can be defined abstract when we want the inheriting class to implement them

if we want to restrict the abstract method implementation to the same package, then the methods can be declared as `default` (access modifier)
    - cat in inheritance package trying to inherit the abstract animal class as parent class

    - if we use `protected` then it can will be subclass restricted