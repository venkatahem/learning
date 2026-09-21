package polymorphism;

public class Test {
    public static void main(String[] args) {
        Polymorphism polymorphism = new Polymorphism();

        // overloading
        System.out.println(polymorphism.add(3, 5));
        System.out.println(polymorphism.add(3, 5, 6));

        // overriding
        Animal cat = new Cat(); // -> Upcasting

        cat.sayHello();

        Animal dog = new Dog();

        dog.sayHello();
        /*
         * dog.sayBye(); -> this doesn't work , since sayBye is not a method of the
         * reference -> Animal
         */

        Cat cat1 = (Cat) cat; // -> downcasting

        Dog dog1 = (Dog) dog; // -> downcasting

        dog1.sayBye(); // works
    }
}
