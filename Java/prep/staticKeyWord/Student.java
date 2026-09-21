package staticKeyWord;

public class Student {

    // shared variable
    public static int count = 0;

    static {
        // to write some logic which can't be written in a single line
        count = 20;
    }

    public Student() {
        count++; // or Student.count++;
    }

}
