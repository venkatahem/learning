import java.util.List;
import java.util.function.Consumer;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class CustomForEach implements Consumer<Integer> {
    public void accept(Integer x) {
        System.out.println(x);
    }
}

public class FuncProg {
    public static void main(String[] args) {
        List<Integer> list = List.of(1, 34, 5, 9, 4, 6, 3, 7, 1, 8, 4, 66, 36, 2, 47, 5, 15, 29, 71);

        List<String> list1 = List.of("Apple", "Ball", "Cat");

        /*
         * printEle(list);
         * printEleCon(list);
         * sumOf(list);
         * sumOfCon(list);
         */

        System.out.println();
        IntStream.range(1, 11).forEach(e -> System.out.println(e));

        list1.stream().map(e -> e.toLowerCase()).forEach(e -> System.out.println(e));

        list1.stream().map(e -> e.length()).forEach(e -> System.out.println(e));

        list1.stream().forEach(e -> {
            System.out.println(e + " - " + e.length());
        });
        System.out.println("Consumer");

        list.stream().forEach(new CustomForEach());

        List<Integer> list2 = list.stream().filter(e -> e % 2 == 0).collect(Collectors.toList());

        List<Integer> list3 = IntStream.range(1, 11).map(e -> e * e).boxed().collect(Collectors.toList());
        /*
         * Returns a
         * InterPipeLine
         * so using
         * boxed() to
         * convert to
         * stream
         */

        System.out.println(list2);
        System.out.println(list3);
    }
    /*
     * public static void printEle(List<Integer> list) {
     * list.stream().forEach(element -> System.out.println(element));
     * System.out.println();
     * }
     * 
     * public static void printEleCon(List<Integer> list) {
     * list.stream().filter(element -> element % 2 == 1).forEach(element ->
     * System.out.println(element));
     * }
     * 
     * public static void sumOf(List<Integer> list) {
     * int sum = list.stream().reduce(0, (num1, num2) -> num1 + num2);
     * 
     * System.out.println("Sum = " + sum);
     * }
     * 
     * public static void sumOfCon(List<Integer> list) {
     * int sum = list.stream().filter(element -> element % 2 == 0).reduce(0, (num1,
     * num2) -> num1 + num2);
     * 
     * System.out.println("Sum(even) = " + sum);
     * int sumOdd = list.stream().filter(element -> element % 2 == 1).reduce(0,
     * (num1, num2) -> num1 + num2);
     * 
     * System.out.println("Sum(Odd) = " + sumOdd);
     * }
     */
}
