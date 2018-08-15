public class FarmLife {
    public static void main(String[] args) {
        Farm farm1 = new Farm();

        farm1.animals.add(new Animal());
        farm1.animals.add(new Animal());
        farm1.animals.add(new Animal());
        farm1.animals.add(new Animal());
        farm1.animals.add(new Animal());

        farm1.animals.get(2).eat();
        farm1.animals.get(0).drink();
        farm1.animals.get(1).play();
        farm1.slaughter();
        farm1.breed();
    }
}
