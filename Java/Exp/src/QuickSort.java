import java.util.ArrayList;

public class QuickSort {
    public static int partition(ArrayList<Integer> arr, int start, int end) {
        int pivot = arr.get(end);
        int pIndex = start;
        // System.out.println("Pivot: " + pivot);
        for (int i = start; i <= end - 1; i++) {
            if (arr.get(i) <= pivot) {
                int temp = arr.get(pIndex);
                arr.set(pIndex, arr.get(i));
                arr.set(i, temp);
                pIndex++;
            }
        }
        int temp = arr.get(pIndex);
        arr.set(pIndex, arr.get(end));
        arr.set(end, temp);
        // System.out.println("Arr: " + arr);
        return pIndex;
    }

    public static void sortQuick(ArrayList<Integer> arr, int start, int end) {

        if (start >= end) {
            return;
        }

        int pIndex = partition(arr, start, end);
        sortQuick(arr, start, pIndex - 1);
        sortQuick(arr, pIndex + 1, end);
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
        sortQuick(arr, 0, arr.size() - 1);
        System.out.println("End: " + arr);
    }
}
