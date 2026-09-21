package inheritance;

public class Parent extends GrandParent {
    // public Parent() {
    // System.out.println("Parent constructor called");
    // }

    private int parentProp;

    public Parent(int age, String name) {
        super(age, name);
        System.out.println("Parent constructor with args");
        this.parentProp = 1;
    }

    public void parentMethod() {
        System.out.println("Parent method");
    }
}
