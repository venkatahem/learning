import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;

public class Student {
    private String name;

    // private int[] marks;
    private ArrayList<Integer> marks = new ArrayList<Integer>();

    Student(String name, int... marks) {
        this.name = name;
        // this.marks = marks;
        for (int i = 0; i < marks.length; i++) {
            this.marks.add(marks[i]);
        }
    }

    int sumMarks() {
        int sum = 0;
        // for (int i = 0; i < this.marks.length; i++) {
        // sum = sum + marks[i];
        // }
        for (int i = 0; i < this.marks.size(); i++) {
            sum = sum + marks.get(i);
        }
        return sum;
    }

    int maxMark() {
        int max = 0;
        // for (int i = 0; i < this.marks.size(); i++) {
        // if (marks[i] > max) {
        // max = marks[i];
        // }
        // }
        for (int i = 0; i < this.marks.size(); i++) {
            if (marks.get(i) > max) {
                max = marks.get(i);
            }
        }
        return max;
    }

    int minMark() {
        int min = 100;
        // for (int i = 0; i < this.marks.size(); i++) {
        // if (marks[i] < min) {
        // min = marks[i];
        // }
        // }
        for (int i = 0; i < this.marks.size(); i++) {
            if (marks.get(i) < min) {
                min = marks.get(i);
            }
        }
        return min;
    }

    BigDecimal averageMarks() {
        return new BigDecimal(sumMarks()).divide(new BigDecimal(marks.size()), 2, RoundingMode.UP);
    }
}