package sorting;

import java.util.Arrays;

public class MergeSort {

    private static void merge(int[] arr, int[] left, int[] right) {
        int l = left.length;
        int r = right.length;
        int i, j, k;
        i = j = k = 0;
        while (j < l && k < r) {
            if (left[j] <= right[k]) {
                arr[i] = left[j];
                j++;
            } else {
                arr[i] = right[k];
                k++;
            }
            i++;
        }
        while (j < l) {
            arr[i] = left[j];
            j++;
            i++;
        }
        while (k < r) {
            arr[i] = right[k];
            i++;
            k++;
        }
    }

    private static void mergeSort(int[] arr) {
        int length = arr.length;
        if (length < 2) {
            return;
        }
        int mid = length / 2;
        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, length);
        mergeSort(left);
        mergeSort(right);
        merge(arr, left, right);
    }

    public static void main(String[] args) {
        int[] arr = { 4, 6, 1, 6, 28, 9, 10, 23, 41, 2, 3, 6, 8, -3, 1, 999, -999, -12 };
        mergeSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
