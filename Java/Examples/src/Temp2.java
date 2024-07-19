import java.util.ArrayList;

public class Temp2 {
    public static int fun(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> a = new ArrayList<>(arr);
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3 };
        System.out.println(fun(arr));
    }
}