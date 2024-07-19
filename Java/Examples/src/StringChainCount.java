import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class StringChainCount {
    public static int sCC(ArrayList<String> words) {
        int x = -1;
        System.out.println(words);
        for (String s : words) {
            if (s.length() > 1) {
                ArrayList<Integer> ans = new ArrayList<>();
                solve(words, s, s, ans, 0);
                if (ans.size() != 0) {
                    x = Math.max(x, Collections.max(ans));
                }

            }
        }
        return x;
    }

    public static void solve(ArrayList<String> words, String word, String curWord, ArrayList<Integer> sol, int temp) {

        if (words.contains(curWord)) {
            if (!word.equals(curWord)) {
                if (curWord.length() == 1) {
                    temp++;
                    sol.add(temp + 1);
                    return;
                } else {
                    temp++;
                    sol.add(temp + 1);
                }
            }

        } else {
            return;
        }

        for (int i = 0; i < curWord.length(); i++) {
            StringBuffer tempWord = new StringBuffer(curWord);
            if (curWord.length() != 1) {
                tempWord.deleteCharAt(i);
            }
            solve(words, word, tempWord.toString(), sol, temp);
        }
    }

    public static void main(String[] args) {
        ArrayList<String> words = new ArrayList<>();
        int x;
        words.add("a");
        words.add("b");
        words.add("ba");
        words.add("bca");
        // words.add("bda");
        words.add("bcda");
        words.add("bcdaa");
        words.add("zbcdaa");
        x = sCC(words);
        System.out.println(x);
    }
}
