package sorting;

import java.util.Arrays;

public class SelectionSort {

    private static void selectionSort(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            int index = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[index] > arr[j]) {
                    index = j;
                }
            }
            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }
    }

    public static void main(String[] args) {
        int[] arr = { 4, 6, 1, 6, 28, 9, 10, 23, 41, 2, 3, 6, 8, -3, 1, 999, -999, -12 };
        selectionSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
