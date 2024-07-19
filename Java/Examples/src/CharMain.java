public class CharMain {
    public static void main(String[] args) {
        Char x = new Char('9');

        System.out.println(x.isAlphabet());
        System.out.println(x.isNum());
        System.out.println(x.isVowel());

        x.upperCase();
        x.lowerCase();

        Char.printUpperCase();
        Char.printLowerCase();
    }
}
