package inheritance;

public class Dog extends Animal {

    public Dog(String name, int age) {
        super(name, age);
    }

    @Override
    public void sayHello() {
        getName();
        System.out.println(" says woof");
    }

    // public void sayHello(){

    // }

}
