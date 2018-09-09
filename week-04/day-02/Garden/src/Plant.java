public class Plant {
    private String color;
    private double absorbWater;
    private double maxWaterLevel;
    private double initialWaterLevel;

    public String getColor() {
        return color;
    }

    public double getAbsorbWater() {
        return absorbWater;
    }

    public double getMaxWaterLevel() {
        return maxWaterLevel;
    }

    public double getInitialWaterLevel() {
        return initialWaterLevel;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setAbsorbWater(double absorbWater) {
        this.absorbWater = absorbWater;
    }

    public void setMaxWaterLevel(double maxWaterLevel) {
        this.maxWaterLevel = maxWaterLevel;
    }

    public void setInitialWaterLevel(double initialWaterLevel) {
        this.initialWaterLevel = initialWaterLevel;
    }

    public void plantStatus(){
        //this instanceof Flower() - true/false, tagja-e az adott classnak
        if (initialWaterLevel<maxWaterLevel){
            System.out.println("The "+ color + " "+ getClass().getName() + " needs water.");
        } else {
            System.out.println("The "+ color + " "+ getClass().getName() + " doesnt need water.");
        }
    }

    public void wateringPlant(double waterAmount){
        initialWaterLevel = initialWaterLevel + absorbWater*waterAmount;
    }
}
