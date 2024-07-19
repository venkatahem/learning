public class StringExe {
    public static void main(String[] args) {
        String str = "This is a string";
        printChar(str);
    }

    static void printChar(String x) {
        int i;
        for (i = 0; i < x.length(); i++) {
            System.out.println(x.charAt(i));
        }
    }
}
