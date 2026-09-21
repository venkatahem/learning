package inheritance;

public class Cat extends Animal {

    public Cat(String name, int age) {
        super(name, age);
    }

    @Override
    public void sayHello() {
        System.out.println("Meow");
    }

}
