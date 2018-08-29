package main.java.animals;

public abstract class Animals {

    private String name;
    private int age;

    public Animals(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public Animals(String name) {
        this.name = name;
        this.age = 1;
    }

    public int getAge() {
        return age;
    }

    public String getName (){
        return name;
    }

    public abstract String breed ();
}
