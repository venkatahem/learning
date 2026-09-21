package inheritance;

public class Animal {

    private String name;

    private int age;

    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void getAge() {
        System.out.println("age - " + this.age);
    }

    public void getName() {
        System.out.println("Name - " + this.name);
    }

    public void sayHello() {
        System.out.println(this.name + " say's hello");
    }

}
