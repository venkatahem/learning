import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int op = 0;
        System.out.println("1 --> Register with tracker\n2 --> Send torrent request");
        op = sc.nextInt();
        if (op == 1) {
            try {

                InetAddress ip = InetAddress.getByName("192.168.212.161");
                Socket client = new Socket(ip, 1234);
                DataInputStream in = new DataInputStream(client.getInputStream());
                DataOutputStream out = new DataOutputStream(client.getOutputStream());
                String send = "New client req";
                String recv = "";
                out.writeUTF(send);
                recv = in.readUTF();
                System.out.println("Msg from server: " + recv);
                client.close();

            } catch (Exception e) {
                System.out.println(e);
            }
        } else if (op == 2) {
            try {

                InetAddress ip = InetAddress.getByName("192.168.212.161");
                ReadTorrClient rtc = new ReadTorrClient();
                Socket client = new Socket(ip, 1234);
                DataInputStream in = new DataInputStream(client.getInputStream());
                DataOutputStream out = new DataOutputStream(client.getOutputStream());
                rtc.displayFiles();
                String send = rtc.sendTorrReq();
                String recv = "";
                out.writeUTF(send);
                recv = in.readUTF();
                System.out.println("Msg from server: " + recv);
                client.close();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        sc.close();
    }
}
