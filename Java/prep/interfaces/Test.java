package interfaces;

public class Test {
    public static void main(String[] args) {
        // Animal cat = new Cat();

        // this is not allowed since jump is a member of Animal interface
        // cat.jump();

        Cat cat4 = new Cat();
        cat4.jump();
        cat4.run();
    }
}
