import java.io.File;
import java.util.Scanner;

public class test {
    Bencode d = new Bencode();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter filename: ");
        String fileName = sc.nextLine();

        File file = new File(fileName);

    }
}
