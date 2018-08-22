public class Student implements Cloneable {

    private String previousOrganization;
    private int skippedDays;
    private String name;
    private int age;
    private String gender;

    public String getPreviousOrganization() {
        return previousOrganization;
    }

    public int getSkippedDays() {
        return skippedDays;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getGender() {
        return gender;
    }

    public Student(String name, int age, String gender, String previousOrganization) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.previousOrganization = previousOrganization;
        skippedDays = 0;
    }

    public Student() {
        skippedDays = 0;
    }

    public void getGoal() {
        System.out.println("Be a junior software developer.");
    }

    public void introduce() {
        System.out.println("Hi, I'm " + name + ", a " + age + "year old" + gender + "from " + previousOrganization + "who skipped" + skippedDays + " days from the coure alredy.");
    }

    public void skipDays(int numberOfDays) {
        skippedDays = skippedDays + numberOfDays;
    }

    @Override
    public Student clone() throws CloneNotSupportedException {
        return (Student) super.clone();
    }
}

