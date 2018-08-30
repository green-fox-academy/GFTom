public class DCHero extends Hero {

    public DCHero(String name, int motivation) {
        super(name, motivation);
    }

    public DCHero(String name) {
        super(name, 45);
    }

    @Override
    public void punch(Punchable other) {
        if (other instanceof MarvelHero) {
            super.punch(other);
        }
    }
}
