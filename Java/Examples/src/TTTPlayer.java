public class TTTPlayer {
    private String name;
    private char symbol;

    public TTTPlayer(String name, char symbol) {
        this.name = name;
        this.symbol = symbol;
    }

    char getSymbol() {
        return this.symbol;
    }

    String getName() {
        return this.name;
    }

    void placeObj(TTTBoard obj, int i, int j) {
        obj.placeOnBoard(i, j, this.symbol);
    }
}
