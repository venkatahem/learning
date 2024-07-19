public class Sq {
    public static void main(String[] args) {
        squareLimit(8);
    }

    static void squareLimit(int x) {
        int i = 1;
        while (i <= x) {
            System.out.println(i * i);
            i++;
        }
    }
}