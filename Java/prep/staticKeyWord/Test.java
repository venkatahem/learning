package staticKeyWord;

public class Test {
    public static void main(String[] args) {
        Student student1 = new Student();
        Student student2 = new Student();
        Student student3 = new Student();
        Student student4 = new Student();

        System.out.println(Student.count);
        System.out.println(student1.count);

        // School school = new School();
        School school = School.getSchool();
    }
}
