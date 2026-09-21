package inheritance;

// Multi level inheritance

public class Child extends Parent {
    // public Child() {
    // super(); // -> implicit
    // System.out.println("Child constructor called");
    // }

    public Child(int age, String name) {
        super(age, name);
        System.out.println("Child constructor with args");
    }

    public void childMethod() {
        super.parentMethod(); // -> can be used on other parent methods
        System.out.println("Child method");
    }
}
