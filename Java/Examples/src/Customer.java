public class Customer {
    private String name;
    private CustomerAddress homeAddress;
    private CustomerAddress workAddress;

    public Customer(String name, CustomerAddress homeAddress) {
        this.name = name;
        this.homeAddress = homeAddress;
    }

    public void setWorkAddress(CustomerAddress wCustomerAddress) {
        this.workAddress = wCustomerAddress;
    }

    public String toString() {
        return String.format("Name: %s, home address - [ %s ], work address - [ %s ]", name, homeAddress, workAddress);
    }
}
