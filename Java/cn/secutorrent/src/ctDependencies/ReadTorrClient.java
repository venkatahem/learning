package ctDependencies;
import java.io.*;
import java.util.Objects;
import java.util.Scanner;

public class ReadTorrClient {

    public void displayFiles() throws Exception {
        try {
//            String path = System.getProperty("user.dir");
            String path = "C:\\Users\\dkvhe\\OneDrive\\Documents\\vs_code\\Java\\cn\\secutorrent\\resources";
            File f = new File(path);

            FilenameFilter filter = new FilenameFilter() {
                @Override
                public boolean accept(File f, String name) {
                    return name.endsWith(".torrent");
                }
            };

            File[] files = f.listFiles(filter);
            System.out.println("Torrent files available");

            for (int i = 0; i < Objects.requireNonNull(files).length; i++) {
                System.out.println(files[i].getName());
            }
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }

    public String sendTorrReq() throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter filename: ");
        String fileName = sc.nextLine();
        String fileReq = "C:\\Users\\dkvhe\\OneDrive\\Documents\\vs_code\\Java\\cn\\secutorrent\\resources\\"+fileName;

        File file = new File(fileReq);

        BufferedReader br = new BufferedReader(new FileReader(file));

        String st;
        StringBuilder content = new StringBuilder();
        while ((st = br.readLine()) != null) {
            System.out.println(st);
            content.append(st);
            Thread.sleep(350);
        }
        sc.close();
        br.close();
        return content.toString();
    }
}
