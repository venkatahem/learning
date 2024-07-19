import java.net.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class TrackerServer {

    public static void addToList(ArrayList<ClientHash> list, String ip) throws Exception {
        List<BlockC> bList = new ArrayList<>();
        AddValidateClients obj = new AddValidateClients();
        ExecutorService exe = Executors.newFixedThreadPool(5);
        for (int i = 0; i < 5; i++) {
            BlockC bObj = new BlockC(list, ip, obj, 1, list.size());
            bList.add(bObj);
        }

        String result = exe.invokeAny(bList);

        System.out.println(result);

        exe.shutdown();
    }

    public static boolean validateClient(ArrayList<ClientHash> list, String torrReq) {
        AddValidateClients obj = new AddValidateClients();
        String hash = "";
        for (int i = 0; i < torrReq.length(); i++) {
            char ch = torrReq.charAt(i);
            if (Character.compare(ch, ':') == 0) {
                String str = torrReq.substring(i + 1, i + 9);
                // System.out.println("Str: " + str);
                if (str.equals("authHash")) {
                    int j = i + 9;
                    String size = "";
                    while (Character.compare(':', torrReq.charAt(j)) != 0) {
                        size = size + torrReq.charAt(j);
                        j++;
                    }
                    int k = Integer.parseInt(size.trim());
                    System.out.println(k);
                    hash = torrReq.substring(j + 1, j + k + 1);
                    System.out.println("Hash: " + hash);
                    break;
                }
            }
        }

        return obj.validate(list, hash);
    }

    public static void main(String[] args) throws Exception {
        int mOp = 0;
        boolean flag = true;
        HashIP hash = new HashIP();
        Scanner sc = new Scanner(System.in);
        ArrayList<ClientHash> cList = new ArrayList<>();
        while (flag) {
            System.out.print("1 --> Accept client request\n2 --> Serve client\n3 --> Close\nChoose: ");
            mOp = sc.nextInt();
            if (mOp == 1) {
                try {
                    DatagramSocket server = new DatagramSocket(12346);

                    int op = 0;
                    byte[] send = new byte[1024];
                    byte[] recv = new byte[1024];
                    DatagramPacket recPac = new DatagramPacket(recv, 1024);
                    server.receive(recPac);
                    String clientMsg = new String(recPac.getData(), 0, recPac.getLength());
                    System.out.println("Msg from client: " + clientMsg);
                    String temp = clientMsg.trim();
                    if (temp.equals("New client req")) {
                        System.out.print("1 --> Add client to list\n2 --> Deny request\nOption: ");
                        op = sc.nextInt();
                        if (op == 1) {
                            String ip = recPac.getAddress().toString();
                            System.out.println("ip: " + ip);
                            String ipHash = String.valueOf(hash.getHash(ip));
                            addToList(cList, ipHash);
                            String reply = "Request accepted and successfully added to the list";
                            send = reply.getBytes();
                        } else if (op == 2) {
                            String reply = "Request denied";
                            send = reply.getBytes();
                        }
                    } else {
                        String reply = "Not a valid request";
                        send = reply.getBytes();
                    }

                    DatagramPacket sendPac = new DatagramPacket(send, send.length, recPac.getAddress(),
                            recPac.getPort());
                    server.send(sendPac);

                    server.close();
                } catch (Exception e) {
                    System.out.println(e);
                }
            } else if (mOp == 2) {
                try {
                    DatagramSocket server = new DatagramSocket(12346);
                    byte[] send = new byte[1024];
                    byte[] recv = new byte[1024];
                    DatagramPacket recPac = new DatagramPacket(recv, 1024);
                    server.receive(recPac);
                    String clientMsg = new String(recPac.getData(), 0, recPac.getLength());
                    System.out.println("Msg from client: " + clientMsg);
                    String temp = clientMsg.trim();
                    if (validateClient(cList, temp)) {
                        String reply = "Valid client";
                        send = reply.getBytes();
                    } else {
                        String reply = "Not a valid request";
                        send = reply.getBytes();
                    }

                    DatagramPacket sendPac = new DatagramPacket(send, send.length, recPac.getAddress(),
                            recPac.getPort());
                    server.send(sendPac);

                    server.close();
                } catch (Exception e) {
                    System.out.println(e);
                }
            } else if (mOp == 3) {
                System.out.println("Closing server");
                flag = false;
            } else {
                System.out.println("Invalid option");
            }
        }
        sc.close();
    }
}
