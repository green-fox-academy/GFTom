import java.util.ArrayList;
import java.util.List;

public class SharpieSet {

    List<Sharpie> sharpies;

    public SharpieSet() {
        sharpies = new ArrayList<>();
    }

    public int countUsable() {

        List<Sharpie> usableSharpie = new ArrayList<>();
        List<Sharpie> removeTrash = new ArrayList<>();
        for (int i = 0; i < sharpies.size(); i++) {
            if (sharpies.get(i).isSharpieUsable()) {
                usableSharpie.add(sharpies.get(i));

            } else {
                removeTrash.add(sharpies.get(i));
            }
        }


        for (int i = 0; i < removeTrash.size(); i++) {
            sharpies.remove(removeTrash.get(i));
        }

        return usableSharpie.size();
    }
    public void addSharpieToList(Sharpie sharpieZero) {
        sharpies.add(sharpieZero);
    }
}
