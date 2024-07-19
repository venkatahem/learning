public class CustomerRun {
    public static void main(String[] args) {
        CustomerAddress homeAddress = new CustomerAddress("line 1", "Vizag", 500123);
        Customer cus1 = new Customer("Hari", homeAddress);

        System.out.println(cus1);
        CustomerAddress workAddress = new CustomerAddress("line 3", "Vizag", 516125);
        cus1.setWorkAddress(workAddress);

        System.out.println(cus1);
    }
}
