public class NumToBin {
    public static void toBinary(int decimal) {
        int binary[] = new int[40];
        int index = 0;
        System.out.println("Binary of " + decimal + " is: ");
        if (decimal == 0) {
            System.out.println("0");
        } else {
            while (decimal > 0) {
                binary[index++] = decimal % 2;
                decimal = decimal / 2;
            }

            for (int i = index - 1; i >= 0; i--) {
                System.out.print(binary[i]);
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        toBinary(0);

        toBinary(10);

    }
}