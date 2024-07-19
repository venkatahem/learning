public class LinkedListRun {
    public static void main(String[] args) {
        LinkedList list1 = new LinkedList();

        list1.insertData(list1, 5);
        list1.insertData(list1, 8);
        list1.insertData(list1, 2);
        list1.insertData(list1, 6);

        list1.printList(list1);
        System.out.println("\n");
        list1.deleteNode(list1, 5);
        list1.printList(list1);
    }
}
