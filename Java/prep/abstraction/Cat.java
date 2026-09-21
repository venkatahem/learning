package abstraction;

public class Cat extends Animal {

    public Cat(String name) {
        super(name);
    }

    @Override
    public void hello() {
        System.out.println("meow");
    }

    @Override
    void bye() {
        System.out.println("bye byee");
    }

}
