class Task1 extends Thread {
    public void run() {
        System.out.println("T1 - Start");
        for (int i = 0; i < 100; i++) {
            System.out.print("'" + i + "' ");
        }
        System.out.println("T1 - End");
    }
}

class Task2 implements Runnable {

    public void run() {
        System.out.println("T2 - Start");
        for (int i = 100; i < 200; i++) {
            System.out.print("'" + i + "' ");
        }
        System.out.println("T2 - End");
    }
}

class Task3 implements Runnable {

    public void run() {
        System.out.println("T3 - Start");
        for (int i = 200; i < 300; i++) {
            System.out.print("'" + i + "' ");
        }
        System.out.println("T3 - End");
    }
}

public class ThreadProg {
    public static void main(String[] args) throws InterruptedException {
        Task1 t1 = new Task1();
        Task2 t2 = new Task2();

        Thread t2t = new Thread(t2);

        Task3 t3 = new Task3();

        Thread t3t = new Thread(t3);

        // t2t.setPriority(10);
        // t1.setPriority(1);

        t1.start();
        t2t.start();
        t2t.sleep(2000);
        t1.join();

        t3t.start();
    }
}
