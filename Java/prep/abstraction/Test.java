package abstraction;

public class Test {
    public static void main(String[] args) {
        Cat cat = new Cat("Bob");

        cat.hello();

        Animal cat1 = new Cat("Jim");

        cat1.hello();

        /*
         * object for Animal - abstract classes can't be created , since it will have
         * unimplemented methods
         */
        // Animal animal = new Animal();
    }
}
