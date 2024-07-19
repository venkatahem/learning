import java.util.*;

public class MapDemo {
    public static void main(String[] args) {
        Map<String, Integer> m1 = Map.of("Z", 4, "W", 5, "E", 3, "T", 0);
        Map<String, Integer> m2 = new TreeMap<>(m1);
        m2.put("S", null);
        System.out.println();

        System.out.println(m1);
        System.out.println(m2);
        System.out.println(m2.keySet());
        System.out.println(m2.values());
        System.out.println(m2.get("W"));

        System.out.println();
    }
}
