public class OctToHex {
    public static int octalToDecimal(int n) {
        int num = n;
        int dec_value = 0;

        int base = 1;

        int temp = num;
        while (temp != 0) {
            int last_digit = temp % 10;
            temp /= 10;

            dec_value += last_digit * base;

            base *= 8;
        }
        System.out.println("Equivaent decimal value: " + dec_value);
        return dec_value;
    }

    public static String decToHexa(int n) {
        char[] hexaDeciNum = new char[100];

        int i = 0;
        while (n != 0) {
            int temp = 0;

            temp = n % 16;

            if (temp < 10) {
                hexaDeciNum[i] = (char) (temp + 48);
                i++;
            } else {
                hexaDeciNum[i] = (char) (temp + 55);
                i++;
            }
            n /= 16;
        }

        String ans = "";

        for (int j = i - 1; j >= 0; j--) {
            ans += hexaDeciNum[j];
        }
        return ans;
    }

    public static void main(String[] args) {
        int octnum = 5123;

        System.out.println("Octal number: " + octnum);
        // Convert Octal to Decimal
        int decnum = octalToDecimal(octnum);

        // Convert Decimal to Hexadecimal
        String hexnum = decToHexa(decnum);

        System.out.println("Equivalent Hexadecimal Value: " + hexnum);
    }
}
