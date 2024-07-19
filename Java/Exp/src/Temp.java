import java.util.ArrayList;
import java.util.Scanner;

public class Temp {
    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> li = new ArrayList<>();
        ArrayList<Integer> li1 = new ArrayList<>();
        ArrayList<Integer> li3 = new ArrayList<>();
        ArrayList<Integer> li2 = new ArrayList<>();

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        System.out.println(t);

        li1.add(1);
        li1.add(2);
        // li1.add(1);
        li2.add(1);
        li2.add(2);
        li3.add(3);
        li3.add(4);
        li.add(li1);
        li1.add(3);
        if (li.contains(li1)) {
            System.out.println("Yes");
        }
    }
}