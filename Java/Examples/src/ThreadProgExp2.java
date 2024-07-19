import java.util.*;
import java.util.concurrent.*;

class CallableExe implements Callable<Integer> {
    private int x;

    public CallableExe(int y) {
        this.x = y;
    }

    public Integer call() throws Exception {
        Thread.sleep(1000);
        return x * 10 + 5;
    }
}

public class ThreadProgExp2 {
    public static void main(String[] args) throws InterruptedException, ExecutionException {
        List<CallableExe> tasks = new ArrayList<>();
        List<Future<Integer>> fut = new ArrayList<>();
        CallableExe task1 = new CallableExe(20);
        ExecutorService es = Executors.newFixedThreadPool(4);
        ExecutorService es1 = Executors.newSingleThreadExecutor();
        for (int i = 0; i < 10; i++) {
            CallableExe task = new CallableExe(i);
            tasks.add(task);
        }
        Integer f1 = es.invokeAny(tasks);
        System.out.println(f1);
        Future<Integer> f2 = es1.submit(task1);
        System.out.println(f2.get());
        fut = es.invokeAll(tasks);
        for (int i = 0; i < 10; i++) {

            System.out.println(fut.get(i).get());
        }

        es.shutdown();
        es1.shutdown();
    }
}
