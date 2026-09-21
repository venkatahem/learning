package abstraction;

public abstract class Animal {

    private String name;

    private int age;

    public Animal(String name) {
        this.name = name;
    }

    /*
     * methods are made abstract when the implementation doesn't make sense in the
     * parent class , this is later implemented in child class
     */
    public abstract void hello();

    /* abstract classes can still have concrete methods */
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

    /* this makes this method package private */
    abstract void bye();

}
