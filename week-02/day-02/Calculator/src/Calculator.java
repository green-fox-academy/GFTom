import java.util.Scanner;

public class Calculator {
  public static void main(String... args) {

    String type = "Please type in the expression";
    System.out.println(type);

    Scanner scanner = new Scanner(System.in);
    String userImput = scanner.nextLine();

   String[] imputDataSplit = userImput.split(" ");

    System.out.println(getCalculation(imputDataSplit));

    // Create a simple calculator application which reads the parameters from the prompt
    // and prints the result to the prompt.
    // It should support the following operations,
    // create a method named "calculate()":
    // +, -, *, /, % and it should support two operands.
    // The format of the expressions must be: {operation} {operand} {operand}.
    // Examples: "+ 3 3" (the result will be 6) or "* 4 4" (the result will be 16)

    // You can use the Scanner class
    // It should work like this:

    // Start the program
    // It prints: "Please type in the expression:"
    // Waits for the user input
    // Print the result to the prompt
    // Exit
  }

  private static double getCalculation(String[] imputDataSplit) {
    double returnValue = 0;
    double num1 = Double.parseDouble(imputDataSplit[1]);
    double num2 = Double.parseDouble(imputDataSplit[2]);
    if (imputDataSplit[0].equals("*") ){
      returnValue = num1 * num2;
    } else if (imputDataSplit[0].equals("+") ){
      returnValue = num1 + num2;
    } else if(imputDataSplit[0].equals("/") ){
      returnValue = num1 / num2;
    } else if (imputDataSplit[0].equals("-") ){
      returnValue = num1 - num2;
    } else if (imputDataSplit[0].equals("%") ){
      returnValue = num1 % num2;
    }
      return returnValue;
  }
}