package main.java.animals;

import main.java.animals.Animals;

public class Reptile extends Animals {
    public Reptile(String name, int age) {
        super(name, age);
    }

    public Reptile(String name) {
        super(name);
    }

    @Override
    public String breed() {
        return "laying eggs.";
    }
}
