import java.util.Arrays;
import java.util.Scanner;

public class MinimizeInstability {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        Arrays.sort(arr);
        int minInstability = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int max = arr[n - 1];
            int min = arr[0];
            if (i > 0) {
                int[] newArr = new int[n - 1];
                int idx = 0;
                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        newArr[idx++] = arr[j];
                    }
                }

                max = newArr[newArr.length - 1];
                min = newArr[0];
            }

            int instability = max - min;
            minInstability = Math.min(minInstability, instability);
        }
        System.out.println(minInstability);
        scanner.close();
    }
}
