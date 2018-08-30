import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Ship {
    List<Pirates> crew;
    Pirates captain;
    Random random = new Random();

    public Ship() {
        crew = new ArrayList<>();
        captain = null;
    }

    public void fillShip() {
        captain = new Pirates();
        int crewNumber = 25 + random.nextInt(26);
        for (int i = 0; i < crewNumber; i++) {
            //Pirates pirate = new Pirates();
            //crew.add(pirate);
            crew.add(new Pirates());
        }
        pirateShipStatus();
    }

    public void pirateShipStatus() {
        String captainsAliveStatus;
        //if (captain.isDead == true)
        if (captain.isDead) {
            captainsAliveStatus = "dead";
        } else if (captain.isSleeping) {
            captainsAliveStatus = "sleeping";
        } else {
            captainsAliveStatus = "awake";
        }
        System.out.println("This ship's captain is " + captainsAliveStatus + " and he consumed " + captain.rumLevel +
                " rum(s). He has " + crew.size() + "pirates.");
    }

    public boolean battle(Ship otherShip) {
        int scoreOtherShip = 0;
        int scoreThisShip = 0;
        boolean winnerShip = false;
        for (int i = 0; i < this.crew.size(); i++) {
            //if(crew.get(i).isDead == false)
            if (!this.crew.get(i).isDead) {
                scoreThisShip++;
            }
        }
        scoreThisShip = scoreThisShip - this.captain.rumLevel;

        for (int i = 0; i < otherShip.crew.size(); i++) {
            if (!otherShip.crew.get(i).isDead) {
                scoreOtherShip++;
            }
        }
        scoreOtherShip = scoreOtherShip - otherShip.captain.rumLevel;
        if (scoreThisShip > scoreOtherShip) {
            for (int i = 0; i < this.crew.size(); i++) {
                int rumAmount = random.nextInt(4);
                for (int j = 0; j < rumAmount; j++) {
                    this.crew.get(i).drinkSomeRum();
                }
            }
            int rumAmount = random.nextInt(4);
            for (int j = 0; j < rumAmount; j++) {
                this.captain.drinkSomeRum();
            }
            int diePiratesUntil = random.nextInt(19);
            for (int i = 0; i < diePiratesUntil; i++) {
                otherShip.crew.get(i).die();
            }
            winnerShip = true;
        } else {
            for (int i = 0; i < otherShip.crew.size(); i++) {
                int rumAmount = random.nextInt(4);
                for (int j = 0; j < rumAmount; j++) {
                    otherShip.crew.get(i).drinkSomeRum();
                }
            }
            int rumAmount = random.nextInt(4);
            for (int j = 0; j < rumAmount; j++) {
                otherShip.captain.drinkSomeRum();
            }
            int diePiratesUntil = random.nextInt(19);
            for (int i = 0; i < diePiratesUntil; i++) {
                this.crew.get(i).die();
            }
        }
        return winnerShip;
    }
}
