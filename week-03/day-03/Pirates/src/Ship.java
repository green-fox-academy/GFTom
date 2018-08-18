import java.util.ArrayList;
import java.util.List;

public class Ship {
    List<Pirates> crew;
    Pirates captain;

    public Ship() {
        crew = new ArrayList<>();
        captain = null;
    }
}
