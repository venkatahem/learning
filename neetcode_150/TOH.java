public class TOH {

    static int count = 0;

    public static void main(String[] args) {
        toh(3, "Source", "Helper", "Destination");
        System.out.println(count);
    }

    private static void toh(int n, String source, String helper, String dest) {
        count++;
        if (n == 1) {
            System.out.println("Move " + n + " from " + source + " to " + dest);
            return;
        }

        toh(n - 1, source, dest, helper);

        System.out.println("Move " + n + " from " + source + " to " + dest);

        toh(n - 1, helper, source, dest);
    }
}
