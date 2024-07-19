public class TTTBoard {
    private char[][] board = new char[3][3];

    public TTTBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '#';
            }
        }
    }

    void printBoard() {
        System.out.println("Board: ");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(board[i][j] + "    ");
            }
            System.out.println();
            System.out.println();
        }
    }

    void placeOnBoard(int i, int j, char symbol) {
        this.board[i - 1][j - 1] = symbol;
    }
}
