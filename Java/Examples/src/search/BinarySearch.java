package search;

public class BinarySearch {

    private static int binarySearch(int[] arr, int x, int low, int high) {
        if (low > high) {
            return -1;
        }
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] > x) {
            return binarySearch(arr, x, low, mid - 1);
        } else {
            return binarySearch(arr, x, mid + 1, high);
        }
    }

    private static int binarySearch(int[] arr, int x) {
        int low = 0;
        int high = arr.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] > x) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = { -999, -12, -3, 1, 1, 2, 3, 4, 6, 6, 6, 8, 9, 10, 23, 28, 41, 999 };
        System.out.println(binarySearch(arr, 999));
        System.out.println(binarySearch(arr, -12, 0, arr.length));
    }
}
