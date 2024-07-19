import java.util.ArrayList;
import java.util.Scanner;

public class MergeSort {
    public static void merge(ArrayList<Integer> arr, int start, int mid, int end) {
        System.out.println("Start");
        System.out.println(start + " " + " " + mid + " " + end);
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        int i, j, k;
        for (i = start; i <= mid; i++) {
            left.add(arr.get(i));
        }
        for (i = mid + 1; i <= end; i++) {
            right.add(arr.get(i));
        }
        System.out.println(left);
        System.out.println(right);
        i = 0;
        j = 0;
        k = start;
        while (i < left.size() && j < right.size()) {
            if (left.get(i) <= right.get(j)) {
                arr.set(k, left.get(i));
                i++;
            } else {
                arr.set(k, right.get(j));
                j++;
            }
            k++;
        }
        while (i < left.size()) {
            arr.set(k, left.get(i));
            i++;
            k++;
        }
        while (j < right.size()) {
            arr.set(k, right.get(j));
            j++;
            k++;
        }
        System.out.println(arr);
        System.out.println("End");
    }

    public static void mergeSort(ArrayList<Integer> arr, int low, int high) {
        if (low >= high) {
            return;
        }
        // int mid = low + (high - low) / 2;
        int mid = (high + low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(2);
        arr.add(108);
        arr.add(98);
        arr.add(34);
        arr.add(65);
        arr.add(123);
        arr.add(23);
        arr.add(1);
        arr.add(6);
        arr.add(5);
        // int size = sc.nextInt();
        // for (int i = 0; i < size; i++) {
        // int temp = sc.nextInt();
        // arr.add(temp);
        // }
        System.out.println(arr);
        mergeSort(arr, 0, arr.size() - 1);
        System.out.println(arr);

        sc.close();
    }
}
