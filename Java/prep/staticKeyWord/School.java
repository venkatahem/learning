package staticKeyWord;

public class School {
    // single instance
    private static School school = new School();

    private School() {

    }

    public static School getSchool() {
        return school;
    }
}
