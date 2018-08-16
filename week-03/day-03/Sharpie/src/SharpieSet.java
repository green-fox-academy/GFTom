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
            if (sharpies.get(i).inkAmount > 0) {
                usableSharpie.add(sharpies.get(i));

            } else {
                removeTrash.add(sharpies.get(i));
            }
        }
        return usableSharpie.size();
    }
}
