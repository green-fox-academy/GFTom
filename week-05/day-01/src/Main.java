import java.util.ArrayList;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
public class E {


    public class Main {
        public static void main(String[] args) {
            ArrayList<Integer> tomb = new ArrayList<>();
            int tmp = 0;

            tomb.add(2);
            tomb.add(3);
            tomb.add(4);
            tomb.add(2);
            tomb.add(2);
            tomb.add(7);
            tomb.add(6);
            Collections.max(tomb);
            System.out.println(getTMP(tomb, tmp));

        }

        public static int getTMP(ArrayList<Integer> tomb, int tmp) {
            tmp = Collections.max(tomb);
            return tmp;
        }
    }
}
