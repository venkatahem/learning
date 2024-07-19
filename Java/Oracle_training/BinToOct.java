public class BinToOct {
    public static void toOctal(long binaryNumber) {
        int decimal = binToDec(binaryNumber);
        int rem;
        String octal = "";
        char octalchars[] = { '0', '1', '2', '3', '4', '5', '6', '7' };
        while (decimal > 0) {
            rem = decimal % 8;
            octal = octalchars[rem] + octal;
            decimal = decimal / 8;
        }
        System.out.println("Octal of the binary: " + binaryNumber + " is: " + octal);
    }

    public static int binToDec(long binaryNumber) {
        int decNum = 0, i = 0;
        while (binaryNumber > 0) {
            decNum += Math.pow(2, i++) * (binaryNumber % 10);
            binaryNumber /= 10;
        }
        System.out.println("In Decimal=" + decNum);
        return decNum;
    }

    public static void main(String args[]) {

        toOctal(11);

    }
}
