import java.util.Scanner;

public class UserInput {
    public static void main(String[] args) {
        Scanner MyObj = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int a = MyObj.nextInt();
        System.out.print("Enter a string: ");
        String str = MyObj.next();
        System.out.printf("Entered num is %d", a).println();
        System.out.printf("Entered num is %s", str).println();
    }
}