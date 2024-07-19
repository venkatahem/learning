import java.util.*;

public class StuRun {
    public static void main(String[] args) {
        List<Stu> stuList = List.of(new Stu(1, "Abhi"), new Stu(10, "Eshwar"), new Stu(4, "Balaji"));
        List<Stu> stuListAl = new ArrayList<>(stuList);
        System.out.println(stuListAl);

        Collections.sort(stuListAl);
        System.out.println(stuListAl);
    }
}
