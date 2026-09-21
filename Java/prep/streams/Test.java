package streams;

public class Test {
    public static void main(String[] args) {
        Job job = new Job() {
            @Override
            public void jobType() {
                System.out.println("Software");
            }
        };

        job.jobType();

        Job job2 = () -> System.out.println("Networks");
        job2.jobType();
    }
}
