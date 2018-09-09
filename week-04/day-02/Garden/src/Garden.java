import java.util.ArrayList;
import java.util.List;

public class Garden {
    List<Plant> garden;

    public Garden() {
        garden = new ArrayList<>();
    }

    public void wateringGarden(int water){
        System.out.println("Watering with "+ water);
        int countThirstyPlant = 0;
        for (Plant plants:garden) {
            if (plants.getInitialWaterLevel()<plants.getMaxWaterLevel()){
                countThirstyPlant++;
            }
        }
        for (Plant plants:garden) {
            if (plants.getInitialWaterLevel()<plants.getMaxWaterLevel()){
                plants.wateringPlant(water/countThirstyPlant);
            }
        }
        gardenStatus();
    }

    public void gardenStatus(){
        for (Plant plant:garden) {
           plant.plantStatus();
        }
        System.out.println();
    }
}
