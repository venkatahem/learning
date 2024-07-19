public class Rec1 {
    public static void main(String[] args) {
        print(10);
        printn(10);
        System.out.println(factorial(6));
    }

    public static void print(int n) {
        if (n < 1) {
            return;
        }
        System.out.println(n);
        print(n - 1);
    }

    public static void printn(int n) {
        if (n < 1) {
            return;
        }
        printn(n - 1);
        System.out.println(n);
    }

    public static int factorial(int n) {
        if (n < 1) {
            return 1;
        }

        return n * factorial(n - 1);
    }
}