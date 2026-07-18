package sorting;

public class NoOfRotations {
    private static int noOfRotations(int arr[]) {
        int low = 0;
        int high = arr.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int prev = (mid + arr.length - 1) % arr.length;
            int next = (mid + 1) % arr.length;
            if (arr[low] <= arr[high]) {
                return low;
            }
            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
                return mid;
            } else if (arr[mid] <= arr[high]) {
                high = mid - 1;
            } else if (arr[mid] >= arr[low]) {
                low = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = { 12, 2, 3, 5, 8, 11 };
        System.out.println(noOfRotations(arr));
    }
}
