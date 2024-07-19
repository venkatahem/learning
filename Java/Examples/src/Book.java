public class Book {
    private int noOfBooks;

    // Default constructor
    Book() {

    }

    // constructor - name should be same as class
    Book(int a) {
        this.noOfBooks = a;
    }

    void bookQunatity(int x) {
        this.noOfBooks = x;
    }

    void increaseQuantity(int x) {
        this.noOfBooks = this.noOfBooks + x;
    }

    void decreaseQuantity(int x) {
        this.noOfBooks = this.noOfBooks - x;
    }

    int getQuantity() {
        return this.noOfBooks;
    }
}