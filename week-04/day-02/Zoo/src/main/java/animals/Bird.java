package main.java.animals;

import main.java.animals.Animals;

public class Bird extends Animals {

    public Bird(String name, int age) {
        super(name, age);
    }

    public Bird(String name) {
        super(name);
    }

    @Override
    public String breed() {
        return "laying eggs.";
    }
}
