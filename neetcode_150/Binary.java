public class Binary {
    public static void main(String[] args) {
        int[] array = { 2, 4, 6, 7, 34, 56, 67, 743, 834, 4363, 373454 };

        int high = array.length - 1;
        int low = 0;

        int x = 8340;

        while (high >= low) {
            int mid = ((high - low) / 2) + low;

            if (array[mid] == x) {
                System.out.println("Position: " + mid);
                break;
            } else if (array[mid] > x) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // System.out.println("Element " + x + " doesn't exist in the array");
    }
}
