public class Sum {
  public static void main(String[] args) {
    //  Create the usual class wrapper
//  and main method on your own.

// - Write a function called `sum` that sum all the numbers
//   until the given parameter and returns with an integer

    int until = 5;
    int summary = sum(until);
    System.out.println(summary);
  }
  public static int sum(int until) {
    int tempSum = 0;
    for (int i = 1; i <= until; i++) {
      tempSum = tempSum + i;
    }
    return tempSum;
  }
}
