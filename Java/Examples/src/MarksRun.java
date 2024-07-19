public class MarksRun {
    public static void main(String[] args) {
        int[] marks = { 94, 89, 93, 95, 92 };
        Student s1 = new Student("Sai", marks);
        // Student s1 = new Student("Sai", 94,89,93,95,92);

        System.out.println("Total = " + s1.sumMarks());
        System.out.println("Max mark = " + s1.maxMark());
        System.out.println("Min mark = " + s1.minMark());
        System.out.println("Average marks = " + s1.averageMarks());
    }
}
