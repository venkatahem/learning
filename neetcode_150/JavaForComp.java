import java.util.*;

public class JavaForComp {
    public static void main(String[] args) {

        // Array list
        List<Integer> list = new ArrayList<>();
        list.add(5); // add
        list.add(0, 10); // insert at index
        list.get(0); // access
        list.set(0, 20); // update
        list.remove(0); // remove by index
        list.remove(Integer.valueOf(20)); // remove by value
        list.size();
        list.contains(5);
        Collections.sort(list); // ascending
        Collections.sort(list, Collections.reverseOrder()); // descending
        Collections.reverse(list);
        int[] arr = list.stream().mapToInt(i -> i).toArray(); // to array

        // Hashmap
        Map<Integer, Integer> map = new HashMap<>(); // O(1), no order
        map.put(1, 100);
        map.get(1); // 100
        map.getOrDefault(2, 0); // 0 if absent
        map.containsKey(1);
        map.merge(1, 5, Integer::sum); // map[1] += 5
        for (Map.Entry<Integer, Integer> e : map.entrySet())
            System.out.println(e.getKey() + " " + e.getValue());

        TreeMap<Integer, Integer> tm = new TreeMap<>(); // sorted keys, O(log n)
        tm.firstKey();
        tm.lastKey();
        tm.ceilingKey(5); // >=5
        tm.floorKey(5); // <=5
        tm.higherKey(5); // >5
        tm.lowerKey(5); // <5

        // LinkedHashMap = insertion order preserved

        // HashSet
        Set<Integer> set = new HashSet<>(); // O(1), no order
        set.add(5);
        set.remove(5);
        set.contains(5);

        TreeSet<Integer> ts = new TreeSet<>(); // sorted, O(log n)
        ts.first();
        ts.last();
        ts.ceiling(5);
        ts.floor(5);
        ts.higher(5);
        ts.lower(5);

        // Dequeue / ArrayDequeue (stack + queue + sliding window)
        Deque<Integer> dq = new ArrayDeque<>();
        dq.addFirst(1);
        dq.addLast(2);
        dq.peekFirst();
        dq.peekLast();
        dq.pollFirst();
        dq.pollLast(); // remove & return, null if empty

        // Use as Stack:
        dq.push(1);
        dq.pop();
        dq.peek();

        // Use as Queue:
        dq.offer(1);
        dq.poll();
        dq.peek();

        // Priority Queue / heap
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(); // min-heap default
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]); // custom comparator
        pq.offer(new int[] { 3, 5 });
        pq.poll(); // removes & returns smallest
        pq.peek();

        // Arrays utility class
        int[] a = { 5, 3, 1 };
        Arrays.sort(a); // primitives: ascending only
        Integer[] b = { 5, 3, 1 };
        Arrays.sort(b, Collections.reverseOrder()); // objects: any comparator
        Arrays.fill(a, 0);
        int[] b2 = { 5, 3, 1 };
        Arrays.equals(a, b2);
        Arrays.copyOf(a, 5);
        Arrays.copyOfRange(a, 1, 3);
        Arrays.asList(1, 2, 3); // fixed-size list
        Arrays.toString(a); // debug print
        int[][] mat = new int[3][4];
        for (int[] row : mat)
            Arrays.fill(row, -1);

        // Collections
        Collections.max(list);
        Collections.min(list);
        Collections.sort(list);
        Collections.reverse(list);
        Collections.swap(list, 0, 1);
        Collections.frequency(list, 5);
        Collections.emptyList();
        Collections.unmodifiableList(list);

        // String builder
        StringBuilder sb = new StringBuilder();
        sb.append("abc").append(1);
        sb.reverse();
        sb.deleteCharAt(0);
        sb.insert(0, "x");
        sb.charAt(0);
        sb.setCharAt(0, 'y');
        sb.toString();
        sb.length();
    }
}
