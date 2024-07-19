
import java.util.*;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Task extends Thread {
    private int n;

    public Task(int x) {
        this.n = x;
    }

    public void run() {
        System.out.println("T" + n + " Starts");
        for (int i = n * 10; i < (n + 1) * 10; i++) {
            System.out.print("'" + i + "' ");
        }
        System.out.println("\nT" + n + " Ends");
    }
}

public class ThreadProgExp1 {
    public static void main(String[] args) {
        List<Task> tasks = new ArrayList<>();
        Task t1 = new Task(0);
        Task t2 = new Task(1);
        Task t3 = new Task(2);
        Task t4 = new Task(3);
        Task t5 = new Task(4);
        Task t6 = new Task(5);
        Task t7 = new Task(6);
        // ExecutorService es = Executors.newSingleThreadExecutor();
        ExecutorService es = Executors.newFixedThreadPool(2);
        // ExecutorService es = Executors.newFixedThreadPool(2);
        for (int i = 0; i < 8; i++) {
            Task task = new Task(i);
            tasks.add(task);
        }
        // es.execute(t1);
        // es.execute(t2);
        // es.execute(t3);
        // es.execute(t4);
        // es.execute(t5);
        // es.execute(t6);
        // es.execute(t7);
        es.execute(tasks.get(2));

        es.shutdown();
    }
}
