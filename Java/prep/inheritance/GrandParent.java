package inheritance;

public class GrandParent {
    private String name;

    private int age;

    // public GrandParent() {
    // System.out.println("Grand Parent constructor called");
    // }

    public GrandParent(int age, String name) {
        System.out.println("Grand Parent constructor with args");
        this.age = age;
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void grandParentMethod() {
        System.out.println("GP Method");
    }

}
