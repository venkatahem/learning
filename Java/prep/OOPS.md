- Deals with objects and classes
- Objects have properties and behaviour 
- Class is a blueprint for object
    - they have properties and behaviour defined

```java
public class Car{
    int speed;
    int price;

    public int break(){
        this.speed--;
        return speed;
    }
}
```

Principles of OOPS

- Encapsulation
    - Packing / bundling of properties and behavior (data and methods) into a single class. Also hides data using access modifiers and provides methods to access them.
- Polymorphism
    - Same code / method behaves differenctly based on the condition.
    - Runtime polymorphism 
        - Method overriding
    - Compile time polymorphism
        - Method overloading
- Inheritance
    - A child class inherits behaviour from a parent class using the extends keyword, promotes code reusability
- Abstraction
    - Hides the implementation details from the user.

