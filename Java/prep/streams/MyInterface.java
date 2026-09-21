package streams;

@FunctionalInterface
public interface MyInterface {

    void hello();

    default void hi() {
        System.out.println("hi");
    }

}
