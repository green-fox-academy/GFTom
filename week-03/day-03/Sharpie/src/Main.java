public class Main {
    public static void main(String[] args) {
        Sharpie Sharpie1 = new Sharpie("blue", 0.75F, 65);
        Sharpie Sharpie2 = new Sharpie("green", 0.75F, 0);
        Sharpie Sharpie3 = new Sharpie("yellow", 0.75F, 70);
        Sharpie Sharpie4 = new Sharpie("brown", 0.75F, 90);
        Sharpie Sharpie5 = new Sharpie("gray", 0.75F, 0);
        Sharpie Sharpie6 = new Sharpie("orange", 0.75F, 2);
        Sharpie Sharpie7 = new Sharpie("pink", 0.75F, 0);

        SharpieSet SharpieSet1 = new SharpieSet();

        SharpieSet1.addSharpieToList(Sharpie1);
        SharpieSet1.addSharpieToList(Sharpie2);
        SharpieSet1.addSharpieToList(Sharpie3);
        SharpieSet1.addSharpieToList(Sharpie4);
        SharpieSet1.addSharpieToList(Sharpie5);
        SharpieSet1.addSharpieToList(Sharpie6);
        SharpieSet1.addSharpieToList(Sharpie7);
    }
}
