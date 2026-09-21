package streams;

import java.util.Arrays;

public class Streams {
    public static void main(String[] args) {
        int[] array = { 1, 2, 3, 4, 5, 6 };

        int sum = Arrays.stream(array).filter(a -> a % 2 == 0).sum();
    }
}
