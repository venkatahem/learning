public class Fan {
    private String maker;
    private double radius;
    private String color;
    private int speed;
    private boolean isOn;

    public Fan(String maker, double radius, String color) {
        this.maker = maker;
        this.radius = radius;
        this.color = color;
    }

    public void switchON(int speed) {
        this.isOn = true;
        this.speed = speed;
    }

    public void switchOff() {
        this.isOn = false;
        this.speed = 0;
    }

    public String toString() {
        return String.format("Maufacturer: %s, radius: %fm, color: %s, is on: %b, speed: %d", maker, radius, color,
                isOn, speed);
    }
}
