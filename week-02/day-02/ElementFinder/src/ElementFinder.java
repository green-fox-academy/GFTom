import java.util.*;

public class ElementFinder{
  public static void main(String... args){
    ArrayList<Integer> arrayList = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
    System.out.println(containsSeven(arrayList));
    // Write a method that checks if the arrayList contains "7" if it contains return "Hoorray" otherwise return "Noooooo"
    // The output should be: "Noooooo"
    // Do this again with a different solution using different list methods!
    System.out.println(containsSeven2(arrayList));
  }

  private static String containsSeven2(ArrayList<Integer> arrayList) {
    String answer1 = "Noooooo";
    for (int i = 0; i < arrayList.size(); i++) {
      if ( arrayList.get(i) == 2 ) {
        answer1 = "Hoorrray";
      }
    }
    return answer1;
  }

  public static String containsSeven(ArrayList<Integer> arrayList) {
    String answer1;
    if (arrayList.contains(7)){
      answer1 = "Hoorrray";
    } else {
      answer1 = "Noooooo";
    }
    return answer1;
  }
}

