public class FanRun {
    public static void main(String[] args) {
        Fan fan1 = new Fan("Bajaj", 0.25, "White");

        fan1.switchON(3);
        System.out.println(fan1);
        fan1.switchOff();
        System.out.println(fan1);
    }
}
