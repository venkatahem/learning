package encapsulation;

public class Test {
    public static void main(String[] args) {
        Student student = new Student(32);

        System.out.println(student.getId());

        student.modifyName("new naemm");

    }
}
