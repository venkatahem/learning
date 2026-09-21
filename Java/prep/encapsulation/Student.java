package encapsulation;

public class Student {
    private int id;
    private String name = "testName";

    public Student(int id) {
        this.id = id;
    }

    public int getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public void modifyName(String name) {
        System.out.println(("Name - " + this.name + " will be modified to " + name));
        this.name = name;

    }
}
