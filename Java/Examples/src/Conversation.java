import java.util.Scanner;

public class Conversation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = "";
        String name = "";
        String[] person1 = { "What is your name?", "Hi ", " How do you do?", "I'm glad to see you ",
                ". What type of programming language do you like?", "I like ",
                " too. Do you find Python as a good replacement for ", "?", "You say '", "'. I wonder why it is?",
                "I'm happy to talk with you that but I have to go now. Bye" };

        for (int i = 0; i < person1.length;) {
            if (i == 0) {
                System.out.println(person1[i]);
                name = sc.nextLine();
                i++;
            } else if (i < person1.length - 2) {
                if (i == 1) {
                    System.out.println(person1[i] + name + person1[i + 1]);
                    str = sc.nextLine();
                    i = i + 2;
                } else if (i == 3) {
                    System.out.println(person1[i] + name + person1[i + 1]);
                    str = sc.nextLine();
                    i = i + 2;
                } else if (i == 5) {
                    System.out.println(person1[i] + str + person1[i + 1] + str + person1[i + 2]);
                    str = sc.nextLine();
                    i = i + 3;
                } else if (i == 8) {
                    System.out.println(person1[i] + str + person1[i + 1]);
                    str = sc.nextLine();
                    i = i + 2;
                }
            } else {
                System.out.println(person1[i]);
                i++;
            }
        }

        sc.close();
    }
}