public class Main {
    public static void main(String[] args) {

        Student student01 = new Student("John", 20, "male", "BME");

        try {
            Student student02 =student01.clone();
            System.out.println(student02.getName());
        } catch (CloneNotSupportedException e){
            e.printStackTrace();
        }

    }
}
