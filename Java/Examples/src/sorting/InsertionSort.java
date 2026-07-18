package sorting;

import java.util.Arrays;

public class InsertionSort {
    private static void insertionSort(int[] arr) {
        int n = arr.length;
        int value;
        int hole;
        for (int i = 0; i < n; i++) {
            value = arr[i];
            hole = i;
            while (hole > 0 && arr[hole - 1] > value) {
                arr[hole] = arr[hole - 1];
                hole = hole - 1;
            }
            arr[hole] = value;
        }
    }

    public static void main(String[] args) {
        int[] arr = { 4, 6, 1, 6, 28, 9, 10, 23, 41, 2, 3, 6, 8, -3, 1, 999, -999, -12 };
        insertionSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
