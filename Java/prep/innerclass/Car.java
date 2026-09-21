package innerclass;

public class Car {
    private boolean isOn;

    private boolean isConditionGood;

    public Car() {
        this.isConditionGood = true;
    }

    public Car(boolean isOn, boolean isConditionGood) {
        this.isOn = isOn;
        this.isConditionGood = isConditionGood;
    }

    // Static inner class
    static class USBPort {
        private String type;

        public USBPort(String type) {
            this.type = type;
        }

        public String getType() {
            return type;
        }
    }

    // Member inner class
    class Engine {
        void start() {
            if (isOn) {
                System.out.println("already on");
            } else {
                isOn = true;
                System.out.println("started");
            }
        }

        void stop() {
            if (isOn) {
                isOn = false;
                System.out.println("stopped");
            } else {
                System.out.println("already stopped");
            }
        }
    }

    public void performMaintenance() {
        // Local inner class
        class Maintenance {
            void checkAndRepair(boolean isConditionGood) {
                if (isConditionGood) {
                    System.out.println("Performing general check...done");
                } else {
                    System.out.println("Fixing issues...done");
                }
            }
        }

        Maintenance maintenance = new Maintenance();
        maintenance.checkAndRepair(this.isConditionGood);
    }

    public void charge(Charger charger) {
        charger.chargeCar();
    }
}
