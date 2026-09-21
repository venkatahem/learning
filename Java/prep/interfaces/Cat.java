package interfaces;

public class Cat implements Animal {
    public void jump() {
        System.out.println("cat Jumped");
    }

    @Override
    public void hello() {
        System.out.println("cat hello");
    }

    @Override
    public void eat() {
        System.out.println("cat eating");
    }
}
