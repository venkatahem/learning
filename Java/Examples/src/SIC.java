import java.math.BigDecimal;

public class SIC {
    private BigDecimal num1;
    private BigDecimal num2;

    SIC(String a, String b) {
        this.num1 = new BigDecimal(a);
        this.num2 = new BigDecimal(b).divide(new BigDecimal(100));
    }

    BigDecimal calTotal(int x) {
        BigDecimal temp = new BigDecimal(x);
        BigDecimal temp1 = this.num1.multiply(this.num2);
        BigDecimal temp2 = temp1.multiply(temp);

        return this.num1.add(temp2);
    }
}
