import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.*;

class FetchWebPage {
    public static void main(String[] args) throws Exception {
        URL url = new URI("https://en.wikipedia.org/wiki/Wikipedia:About").toURL();

        URLConnection con = url.openConnection();

        // Get the input stream through URL Connection
        InputStream input = con.getInputStream();

        // Once you have the Input Stream, it's just plain old Java IO stuff.

        // For this case, since you are interested in getting plain-text web page
        // I'll use a reader and output the text content to System.out.

        // For binary content, it's better to directly read the bytes from stream and
        // write
        // to the target file.

        try (BufferedReader br = new BufferedReader(new InputStreamReader(input))) {
            String line = null;

            // read each line and write to System.out
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        }
    }
}