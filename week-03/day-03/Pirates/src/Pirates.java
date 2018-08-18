import java.util.Random;

public class Pirates {

    int rumLevel;
    boolean isSleeping;
    boolean isDead;
    Random random = new Random();

    public Pirates() {
    }

    public void drinkSomeRum() {
        if (this.isSleeping == false && this.isDead == false) {
            rumLevel++;
            if (rumLevel < 9) {
                die();
            }
        }
    }

    public void howItsGoingMate() {
        if (rumLevel <= 4) {
            System.out.println("Pour me anudder");
        } else if (rumLevel > 4 && rumLevel <= 8) {
            System.out.println("Arghh, I'ma Pirate. How d'ya d'ink its goin?");
            isSleeping = true;
        }
    }

    public void die() {
        isDead = true;
    }

    public void brawl(Pirates pirate) {
        if (pirate.isDead == false && this.isDead == false && this.isSleeping == false && pirate.isSleeping == false) {
            int chance = random.nextInt(3);
            if (chance == 0) {
                this.die();
            } else if (chance == 1) {
                pirate.die();
            } else {
                this.isSleeping = true;
                pirate.isSleeping = true;
            }
        }

    }
}


