public class GaedenApp {

    public static void main(String[] args) {

        Flower flower01 = new Flower("yellow");
        Flower flower02 = new Flower("blue");
        Tree tree01 = new Tree ("purple");
        Tree tree02 = new Tree("orange");

        Garden arboretum = new Garden();
        arboretum.garden.add(flower01);
        arboretum.garden.add(flower02);
        arboretum.garden.add(tree01);
        arboretum.garden.add(tree02);

        arboretum.gardenStatus();
        arboretum.wateringGarden(40);
        arboretum.wateringGarden(70);
    }
}
