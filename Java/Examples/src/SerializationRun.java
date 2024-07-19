import java.io.FileOutputStream;
import java.io.ObjectOutputStream;

public class SerializationRun {
    public static void main(String[] args) throws Exception {
        SerializationObj obj = new SerializationObj();
        obj.num = 20;
        obj.name = "sai";

        SerializationObj obj1 = new SerializationObj();
        obj1.num = 21;
        obj1.name = "siva";

        String file = "ser.txt";

        FileOutputStream f = new FileOutputStream(file);
        ObjectOutputStream ob = new ObjectOutputStream(f);
        ob.writeObject(obj);
        ob.writeObject(obj1);
    }
}