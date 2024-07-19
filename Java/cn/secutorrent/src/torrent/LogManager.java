package torrent;

import java.io.*;
import java.util.*;

/**
 * Utility class to output information to a file
 *
 * @author Baptiste Dubuis
 * @version 0.1
 */
public class LogManager {
    private String filename;
    public FileWriter fw;
    // private OutputStream os;

    public LogManager(String logfile) {
        this.filename = logfile;
    }

    /**
     * Write the given string to the file corresponding to this manager
     * 
     * @param s String
     */
    synchronized public void writeLog(String s) {
        try {
            this.fw = new FileWriter(this.filename, true);
            Date d = new Date();

            this.fw.write(d + " : " + s + "\r\n");
            this.fw.flush();
            this.fw.close();
        } catch (Exception e) {
            System.out.println("Not able to write to log file");
        }
    }

}
