import java.sql.*;
class Student {
    public static void main(String[] args) {
        String[] student_name = {"Sai", "Aravind","Kishore"};
        String[] dept = {"CSE","ECE","Mech"};
        int[] id = {20203001,20204003,20205014};
        try {
            Class.forName("oracle.jdbc.driver.OracleDriver");

            Connection con = DriverManager.getConnection(
                    "jdbc:oracle:thin:@localhost:1521:xe", "system", "venki");

            Statement stmt = con.createStatement();
            stmt.execute("drop table student_details");
            stmt.execute("create table student_details(id number(10), stu_name varchar2(30), dept varchar2(6))");
            for(int i=0;i<3;i++){
                stmt.executeQuery("insert into student_details values("+id[i]+",'"+student_name[i]+"','"+dept[i]+"')");
            }

            System.out.println("Created student table and inserted values");

            ResultSet rs = stmt.executeQuery("select * from student_details");
            System.out.println("Displaying values from student table");
            while (rs.next())
            {
                System.out.println("Student ID: "+rs.getInt(1) + " ,name: " + rs.getString(2) + " & dept: " + rs.getString(3));
            }

            stmt.execute("drop table student_details");
            con.close();

        } catch (Exception e) {
            System.out.println(e);
        }

    }
}