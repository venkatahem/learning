public class CustomerAddress {
    private int zipCode;
    private String line;
    private String city;

    public CustomerAddress(String line, String city, int zipCode) {
        this.line = line;
        this.city = city;
        this.zipCode = zipCode;
    }

    public String toString() {
        return "Line: " + line + ", City: " + city + ", " + "Zipcode: " + zipCode;
    }
}
