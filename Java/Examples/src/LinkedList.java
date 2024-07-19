public class LinkedList {
    Node head;

    public class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public LinkedList insertData(LinkedList list, int data) {
        Node new_node = new Node(data);
        if (list.head == null) {
            list.head = new_node;
        } else {
            Node temp = list.head;

            while (temp.next != null) {
                temp = temp.next;
            }

            temp.next = new_node;
        }

        return list;
    }

    public LinkedList deleteNode(LinkedList list, int data) {
        Node temp, prev;
        temp = list.head;
        prev = list.head;
        if (temp == null) {
            System.out.println("Empty list");
        } else if (temp.data == data) {
            temp = temp.next;
            list.head = temp;
        } else {
            while (temp != null) {
                if (temp.data == data) {
                    break;
                }
                prev = temp;
                temp = temp.next;
            }
            prev.next = temp.next;
        }
        if (temp == null) {
            System.out.println("Data not found");
        }
        return list;
    }

    public void printList(LinkedList list) {
        Node temp = list.head;
        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }
}
