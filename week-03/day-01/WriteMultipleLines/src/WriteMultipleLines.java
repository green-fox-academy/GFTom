import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class WriteMultipleLines {
    public static void main(String[] args) {
        String path2 = "C:\\green-fox\\week-03\\day-01\\WriteMultipleLines\\src\\MultiLines.txt";
        String content = "This is the content.";
        int numOfLines = 9;

        writeToFile(path2, content, numOfLines);
// Create a function that takes 3 parameters: a path, a word and a number,
// than it should write to a file.
// The path parameter should be a string, that describes the location of the file.
// The word parameter should be a string, that will be written to the file as lines
// The number paramter should describe how many lines the file should have.
// So if the word is "apple" and the number is 5, than it should write 5 lines
// to the file and each line should be "apple"
// The function should not raise any error if it could not write the file.
    }
    public static void writeToFile(String path, String content, int numOfLines){
        List<String> contentLines = new ArrayList();
        for (int i = 0; i < numOfLines; i++) {
            contentLines.add(content);
        }
        try {
            Path filePath = Paths.get(path);
            Files.write(filePath, contentLines);
        } catch (Exception e) {
            System.out.println("Uh-oh, could not write the file!");
        }
    }

}
