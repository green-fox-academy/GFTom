import java.util.ArrayList;
import java.util.List;

public class Farm {

    List<Animal> animals;
    int freeSlots;

    public Farm() {
        animals = new ArrayList<>();
        freeSlots = 10;
    }

    public void breed() {
        if (freeSlots > 0) {
            freeSlots = freeSlots - 1;
            animals.add(new Animal());
        }
    }

    public void slaughter() {
        int referenceHunger = animals.get(0).hunger;
        int referenceAnimal = 0;
        for (int i = 0; i < animals.size(); i++) {
            if (animals.get(i).hunger > referenceHunger) {
                referenceHunger = animals.get(i).hunger;
                referenceAnimal = i;
            }
        }
        freeSlots = freeSlots + 1;
        animals.remove(referenceAnimal);
    }
}
