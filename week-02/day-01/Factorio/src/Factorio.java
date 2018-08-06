import java.util.Scanner;

public class Factorio {
  public static void main(String[] args) {
    // - Create a function called `factorio`
//   that returns it's input's factorial
    Scanner scanner = new Scanner(System.in);
    int inputFactorial = scanner.nextInt();
    int resultFactorial = factorio(inputFactorial);
    System.out.println(resultFactorial);
  }

  private static int factorio(int inputFactorial) {
    int outputfactorial = 1;
    for (int i = 1; i <=inputFactorial ; i++) {
      outputfactorial = outputfactorial * i;
    }
    return outputfactorial;
  }
}
