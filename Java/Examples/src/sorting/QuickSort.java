package sorting;

import java.util.Arrays;

public class QuickSort {

    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int pIndex = low;

        for (int i = low; i < high; i++) {
            if (arr[i] <= pivot) {
                int temp = arr[i];
                arr[i] = arr[pIndex];
                arr[pIndex] = temp;
                pIndex++;
            }
        }

        int temp = arr[pIndex];
        arr[pIndex] = pivot;
        arr[high] = temp;
        return pIndex;
    }

    private static int randomPartition(int[] arr, int low, int high) {
        int pivot = (int) (Math.random() * (high - low) + low);
        int temp = arr[pivot];
        arr[pivot] = arr[high];
        arr[high] = temp;

        return partition(arr, low, high);
    }

    private static void quickSort(int[] arr, int low, int high) {
        if (!(low < high)) {
            return;
        }
        int partitionIndex = randomPartition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }

    public static void main(String[] args) {
        int[] arr = { 4, 6, 1, 6, 28, 9, 10, 23, 41, 2, 3, 6, 8, -3, 1, 999, -999, -12 };
        quickSort(arr, 0, arr.length - 1);
        System.out.println(Arrays.toString(arr));
    }
}
