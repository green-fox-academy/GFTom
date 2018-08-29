package main.java.animals;

import main.java.animals.Animals;

public class Mammal extends Animals {

    public Mammal(String name, int age) {
        super(name, age);
    }

    public Mammal(String name) {
        super(name);
    }

    @Override
    public String breed() {
        return "pushing miniature versions out.";
    }
}
