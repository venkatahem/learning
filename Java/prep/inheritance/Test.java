package inheritance;

public class Test {
    public static void main(String[] args) {
        // Animal dog = new Dog("Jim", 3);

        // dog.sayHello();
        // dog.getAge();

        // Child child = new Child();
        Child child = new Child(4, "Bob");

        // child.setName("Bob");

        // Cat cat = new Cat("Jerry", 2);

        // cat.sayHello();

        child.childMethod();
    }
}
