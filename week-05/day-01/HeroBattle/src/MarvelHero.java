public class MarvelHero extends Hero {

    public MarvelHero(String name, int motivation) {
        super(name, motivation);
    }

    public MarvelHero(String name) {
        super(name, 40);
    }

    @Override
    public void punch(Punchable other) {
        if (other instanceof DCHero) {
            super.punch(other);
        }
    }
}
