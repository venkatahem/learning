import java.util.ArrayList;

public class MergeSort {

    public static void Merge(ArrayList<Integer> arr, ArrayList<Integer> left, ArrayList<Integer> right) {
        int i, j, k;
        i = j = k = 0;
        while (i < left.size() && j < right.size()) {
            if (left.get(i) < right.get(j)) {
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
    }

    public static void MergeSorter(ArrayList<Integer> arr) {
        if (arr.size() < 2) {
            return;
        }
        int mid = arr.size() / 2;
        ArrayList<Integer> left = new ArrayList<>(arr.subList(0, mid));
        ArrayList<Integer> right = new ArrayList<>(arr.subList(mid, arr.size()));
        MergeSorter(left);
        MergeSorter(right);
        Merge(arr, left, right);
    }

    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();

        arr.add(2);
        arr.add(12);
        arr.add(1);
        arr.add(291);
        arr.add(129);
        arr.add(43);
        arr.add(900);
        arr.add(65);
        arr.add(32);
        arr.add(62);
        System.out.println("Initial: " + arr);
        MergeSorter(arr);
        System.out.println("End: " + arr);
    }
}
