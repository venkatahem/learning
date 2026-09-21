package enums;

public enum Day {

    // first thing in enum should be constants
    SUN("Sunday"),
    MON("Monday"),
    TUE("Tuesday"),
    WED("Wednesday"),
    THU("Thursday"),
    FRI("Friday"),
    SAT("Saturday");

    private Day(String fullName) {
        System.out.println("Setting fullname for " + this.name() + " fname - " + fullName);
        this.fullName = fullName;
    }

    // fields
    private String fullName;

    public String getFullName() {
        return this.fullName;
    }

    // methods
    public void display() {
        System.out.println("Today is " + this.name());
    }
}

// SUN , MON etc are final instances of day class