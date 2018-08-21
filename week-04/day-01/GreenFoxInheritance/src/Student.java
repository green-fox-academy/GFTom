public class Student extends Person {

    protected String previousOrganization;
    protected int skippedDays;

    public Student(String name, int age, String gender, String previousOrganization) {
        super(name, age, gender);
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
}
