// Java program to convert string X to
// string Y which minimum number of changes.
class GFG {
    static final int MAX = 26;

    static void printAnagramAndChanges(char[] X,
            char[] Y) {
        int countx[] = new int[MAX], county[] = new int[MAX],
                ctrx[] = new int[MAX], ctry[] = new int[MAX];

        int change = 0;
        int l = X.length;

        for (int i = 0; i < l; i++) {
            countx[X[i] - 'A']++;
            county[Y[i] - 'A']++;
        }

        for (int i = 0; i < MAX; i++) {
            if (countx[i] > county[i]) {
                ctrx[i] += (countx[i] - county[i]);
            } else if (countx[i] < county[i]) {
                ctry[i] += (county[i] - countx[i]);
            }
            change += Math.abs(county[i] - countx[i]);
        }

        for (int i = 0; i < l; i++) {
            if (ctrx[X[i] - 'A'] == 0) {
                continue;
            }

            int j;
            for (j = 0; j < MAX; j++) {
                if ((ctry[j]) > 0) {
                    break;
                }
            }

            if (countx[X[i] - 'A'] == ctrx[X[i] - 'A']
                    || X[i] - 'A' > j) {

                countx[X[i] - 'A']--;
                ctrx[X[i] - 'A']--;
                ctry[j]--;
                X[i] = (char) ('A' + j);
            } else {
                countx[X[i] - 'A']--;
            }
        }
        System.out.println("Anagram : " + String.valueOf(X));
        System.out.println("Number of changes made : " + change / 2);
    }

    // Driver code
    public static void main(String[] args) {
        String x = "CDBABC", y = "ADCABD";
        printAnagramAndChanges(x.toCharArray(), y.toCharArray());
    }
}

// This code is contributed by Rajput-Ji
