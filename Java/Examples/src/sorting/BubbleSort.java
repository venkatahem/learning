package sorting;

import java.util.Arrays;

public class BubbleSort {
    private static void bubbleSort(int[] arr) {
        int n = arr.length;
        boolean swap = false;
        for (int i = 0; i < n - 1; i++) {
            swap = false;
            for (int j = 1; j < n; j++) {
                if (arr[j - 1] > arr[j]) {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                    swap = true;
                }
            }
            if (!swap) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = { 4, 6, 1, 6, 28, 9, 10, 23, 41, 2, 3, 6, 8, -3, 1, 999, -999, -12 };
        bubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
