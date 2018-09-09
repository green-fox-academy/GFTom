public class Flower extends Plant{
    public Flower(String color) {
        setAbsorbWater(0.75);
        setColor(color);
        setInitialWaterLevel(0.0);
        setMaxWaterLevel(5.0);
    }
}
