public class BookRun {
    public static void main(String[] args) throws Exception {
        Book HPDH = new Book(10);
        Book HPOP = new Book(11);
        Book HPPA = new Book(21);
        Book DSA = new Book();

        System.out.println("HPDH");
        System.out.println(HPDH.getQuantity());
        System.out.println("HPOP");
        System.out.println(HPOP.getQuantity());
        System.out.println("HPPA");
        System.out.println(HPPA.getQuantity());

        HPDH.bookQunatity(120);
        HPOP.bookQunatity(50);
        HPPA.bookQunatity(70);

        System.out.println("HPDH");
        System.out.println(HPDH.getQuantity());
        System.out.println("HPOP");
        System.out.println(HPOP.getQuantity());
        System.out.println("HPPA");
        System.out.println(HPPA.getQuantity());

        HPDH.increaseQuantity(23);
        HPOP.increaseQuantity(30);
        HPPA.increaseQuantity(12);

        System.out.println("HPDH");
        System.out.println(HPDH.getQuantity());
        System.out.println("HPOP");
        System.out.println(HPOP.getQuantity());
        System.out.println("HPPA");
        System.out.println(HPPA.getQuantity());

        HPDH.decreaseQuantity(42);
        HPOP.decreaseQuantity(31);
        HPPA.decreaseQuantity(11);

        System.out.println("HPDH");
        System.out.println(HPDH.getQuantity());
        System.out.println("HPOP");
        System.out.println(HPOP.getQuantity());
        System.out.println("HPPA");
        System.out.println(HPPA.getQuantity());
    }
}
