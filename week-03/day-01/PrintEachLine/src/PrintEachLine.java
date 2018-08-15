import java.io.File;
import java.io.FileNotFoundException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PrintEachLine {
  public static void main(String[] args) throws FileNotFoundException {
    // Write a program that opens a file called "my-file.txt", then prints
    // each of the lines form the file.
    // If the program is unable to read the file (for example it does not exists),
    // then it should print an error message like: "Unable to read file: my-file.txt"

    File file = new File(my-file);
    Scanner input = new Scanner(file);
    List<String> list = new ArrayList<String>();

    while (input.hasNextLine()) {
      list.add(input.nextLine());
    }
      System.out.println(list.get(0));
    }

  }
