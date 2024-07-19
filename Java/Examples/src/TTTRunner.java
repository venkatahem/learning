import java.util.Scanner;

public class TTTRunner {
    public static void main(String[] args) {
        TTTBoard b1;
        TTTPlayer p1;
        TTTPlayer p2;
        int i, j;
        Scanner sc = new Scanner(System.in);
        System.out.print("Initialize the game(y/n): ");
        if (sc.nextLine().equals("y")) {
            b1 = new TTTBoard();
            System.out.print("Player name: ");
            String pl1 = sc.nextLine();
            System.out.print("Player symbol: ");
            char[] pl1s = sc.nextLine().toCharArray();
            p1 = new TTTPlayer(pl1, pl1s[0]);
            System.out.print("Player name: ");
            String pl2 = sc.nextLine();
            System.out.print("Player symbol: ");
            char[] pl2s = sc.nextLine().toCharArray();
            p2 = new TTTPlayer(pl2, pl2s[0]);

            b1.printBoard();
            boolean flag = true;

            System.out.println("Input the position on the board to mark the symbol");
            while (flag) {
                System.out.println("Input for player 1");
                i = sc.nextInt();
                j = sc.nextInt();
                p1.placeObj(b1, i, j);
                System.out.println("Input for player 1");
                i = sc.nextInt();
                j = sc.nextInt();
                p1.placeObj(b1, i, j);
            }
        }

        sc.close();
    }
}
