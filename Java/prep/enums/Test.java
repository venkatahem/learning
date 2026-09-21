package enums;

public class Test {
    public static void main(String[] args) {
        Day day1 = Day.FRI;
        System.out.println(day1.ordinal());
        System.out.println(day1.name());
        System.out.println(day1.toString());

        Day day2 = Day.valueOf("SAT");

        System.out.println(day2);
    }
}
