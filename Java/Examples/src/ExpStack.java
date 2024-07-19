import java.util.Stack;

public class ExpStack {

    public static void fun(Stack<Integer> s) {
        if (s.empty()) {
            return;
        }
        int val = s.pop();
        fun(s);
        // s.push(val);
        p(s, val);
    }

    public static void p(Stack<Integer> s, int val) {
        if (s.empty()) {
            s.push(val);
            return;
        }
        int temp = s.pop();
        p(s, val);
        s.push(temp);
    }

    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        s.push(0);
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);

        System.out.println(s);
        fun(s);
        System.out.println(s);
    }

}
