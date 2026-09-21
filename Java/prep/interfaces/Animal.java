package interfaces;

public interface Animal {
    // public static final are implicit and need not be written
    public static final int legs = 4;

    // can have default methods from java8
    public default void hello() {
        System.out.println("Hi");
    };

    public static void jump() {
        System.out.println("jump");
    }

    public abstract void eat();

    public default void run() {
        System.out.println("animal is running");
    }
}
