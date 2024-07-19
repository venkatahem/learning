class Count {
    int x;

    public Count() {
        this.x = 0;
    }
}

public class TowerOfHanoi {

    public static void main(String[] args) {
        int helper, source, dest;
        source = 1;
        helper = 2;
        dest = 3;
        int n = 8;
        Count cnt = new Count();
        solve(n, source, dest, helper, cnt);
        System.out.println("Steps: " + cnt.x);
    }

    public static void solve(int n, int source, int dest, int helper, Count c) {
        c.x = c.x + 1;
        if (n == 1) {
            System.out.println("move disk " + n + " from rod " + source + " to rod " + dest);
            return;
        }
        solve(n - 1, source, helper, dest, c);
        System.out.println("move disk " + n + " from rod " + source + " to rod " + dest);
        solve(n - 1, helper, dest, source, c);
    }
}
