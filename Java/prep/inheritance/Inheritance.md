## inheritance

parent class from which a child class can inherit from 

when the properties and behavior is same then they can be defined in a generic method which can be imported 

## method overriding

when child classes implement a method with same name as in parent class , the child method will override the parent method during runtime

## types

`single` level inheritance - parent extends grand parent

`multi` level - child extends parent

`hierarchical` 
cat extends animal
dog extends animal

```
Animal
   |
|----|
Dog  Cat
```

- `construction chaining` , the parent constructor is invoked first when creating a child object

- `multiple` inheritance is not allowed in java, - a single class extending multiple classes -- this is to avoid ambiguity when multiple methods has same method signatures 

# super keyword

`this` keyword is used to access the properties in the same class , whereas the `super` keyword is used to access parent class

call to super should be the first statement in the constructor (this changed from java25)

super can be used to access or invoke parent class constructor , properties and methods

