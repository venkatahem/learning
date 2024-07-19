import java.util.ArrayList;
import java.util.List;

public class ListExp {
    public static void main(String[] args) {

        List<Integer> intList = List.of(1, 3, 2, 4);
        List<Integer> list1 = new ArrayList<Integer>(intList);
        list1.add(2, 2);
        // intList.addAll(list1);
        list1.addAll(intList);
        list1.remove(5);
        // for (int i1 : intList) {
        // System.out.println(i1);
        // }
        for (int i1 : list1) {
            System.out.println(i1);
        }
    }
}
