import java.util.Scanner;

public class SeriesGen {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a: ");
        int a = sc.nextInt();
        System.out.print("Enter b: ");
        int b = sc.nextInt();
        System.out.print("Enter c: ");
        int c = sc.nextInt();
        System.out.print("Enter n: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            a = a + (int) (Math.pow(3, i) * Math.pow(b, i) * c);
            System.out.print(a + " ");
        }

        sc.close();
    }
}