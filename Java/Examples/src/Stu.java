public class Stu implements Comparable<Stu> {
    private String name;
    private int id;

    public Stu(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public String toString() {
        return String.format("ID: %d - Name: %s", this.id, this.name);
    }

    @Override
    public int compareTo(Stu that) {
        return Integer.compare(this.id, that.id);
    }

    // private int compare(int id2, int id3) {
    // if (id2 < id3) {
    // return -1;
    // } else if (id2 > id3) {
    // return 1;
    // }
    // return 0;
    // }
}
