public class Char {
    private char ch;

    Char(char c) {
        this.ch = c;
    }

    boolean isVowel() {
        if (this.ch == 'a' || this.ch == 'e' || this.ch == 'i' || this.ch == 'o' || this.ch == 'u') {
            return true;
        } else if (this.ch == 'A' || this.ch == 'E' || this.ch == 'I' || this.ch == 'O' || this.ch == 'U') {
            return true;
        }
        return false;
    }

    boolean isNum() {
        // if ((this.ch >= 'a' && this.ch <= 'z')) {
        // return false;
        // } else if ((this.ch >= 'A' && this.ch <= 'Z')) {
        // return false;
        // }
        // return true;

        if (this.ch >= 48 && this.ch <= 57) {
            return true;
        }
        return false;
    }

    boolean isAlphabet() {
        return !(this.isNum());
    }

    void upperCase() {
        System.out.println(Character.toUpperCase(this.ch));
    }

    void lowerCase() {
        System.out.println(Character.toLowerCase(this.ch));
    }

    public static void printUpperCase() {
        for (char y = 'a'; y <= 'z'; y++) {
            System.out.printf("%c ", y);
            if (y == 'z') {
                System.out.printf("\n");
            }
        }
    }

    public static void printLowerCase() {
        for (char y = 'A'; y <= 'Z'; y++) {
            System.out.printf("%c ", y);
            if (y == 'Z') {
                System.out.printf("\n");
            }
        }
    }
}
