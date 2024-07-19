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
                DatagramSocket client = new DatagramSocket(12345);
                byte[] send = new byte[1024];
                byte[] recv = new byte[1024];
                InetAddress ad = InetAddress.getByName("127.0.0.1");
                // client.connect(ad, 12346);
                DatagramPacket recPac = new DatagramPacket(recv, 1024);
                String req = "New client req";
                send = req.getBytes();
                DatagramPacket sendPac = new DatagramPacket(send, send.length, ad, 12346);
                client.send(sendPac);
                client.receive(recPac);
                String res = new String(recPac.getData(), 0, recPac.getLength());
                System.out.println("Msg from server/tracker " + res);
                client.close();
            } catch (Exception e) {
                System.out.println(e);
            }
        } else if (op == 2) {
            try {
                DatagramSocket client = new DatagramSocket(12345);
                byte[] send = new byte[1024];
                byte[] recv = new byte[1024];
                ReadTorrClient rtc = new ReadTorrClient();
                rtc.displayFiles();
                DatagramPacket recPac = new DatagramPacket(recv, 1024);
                String req = rtc.sendTorrReq();
                send = req.getBytes();
                DatagramPacket sendPac = new DatagramPacket(send, send.length, InetAddress.getByName("127.0.0.1"),
                        12346);
                client.send(sendPac);
                client.receive(recPac);
                String res = new String(recPac.getData(), 0, recPac.getLength());
                System.out.println("Msg from server/tracker " + res);
                client.close();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        sc.close();
    }
}
