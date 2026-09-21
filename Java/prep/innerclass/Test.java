package innerclass;

public class Test {
    public static void main(String[] args) {
        Car car = new Car();

        Car.Engine engine = car.new Engine();

        engine.stop();

        engine.start();

        engine.start();

        engine.stop();

        Car.USBPort usb1 = new Car.USBPort("C");
        Car.USBPort usb2 = new Car.USBPort("B");

        System.out.println(usb1.getType());

        // the interface is implemented as an anonymous inner class instead of
        // implementing a separate class
        car.charge(new Charger() {
            @Override
            public void chargeCar() {
                System.out.println("Connected and charging car");
            }
        });

        car.performMaintenance();
    }
}
