import java.util.ArrayList;
import java.util.Arrays;

public class SolarSystem {
  public static void main(String... args){
    ArrayList<String> planetList = new ArrayList<String>(Arrays.asList("Mercury","Venus","Earth","Mars","Jupiter","Uranus","Neptune"));
    ArrayList<String> arrlist = new ArrayList<String>(8);
    arrlist.add(7," Saturn");
    // Saturn is missing from the planetList
    // Insert it into the correct position
    // Create a method called putSaturn() which has list parameter and returns the correct list.
    for(Integer number : arrlist)
    System.out.println(putSaturn(planetList));
    // Expected output: "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Uranus", "Neptune", "Saturn"
  }
}
