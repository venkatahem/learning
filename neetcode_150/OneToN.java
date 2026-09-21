public class OneToN {
    public static void main(String[] args) {
        print1ton(3);
        printnto1(3);
    }

    private static void print1ton(int n) {
        if (n == 0) {
            return;
        }

        print1ton(n - 1);

        System.out.println(n);
    }

    private static void printnto1(int n) {
        if (n == 0) {
            return;
        }

        System.out.println(n);

        printnto1(n - 1);
    }
}
