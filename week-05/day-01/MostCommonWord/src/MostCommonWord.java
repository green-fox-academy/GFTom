import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MostCommonWord{
    public static void main(String[] args) {
            String fileName = "test.txt";
        System.out.println(getMostCommonWord(fileName));

        // Create a simple word counter function which returns the most common string (word) in a file.
        // The function should take one argument which is the filename.
        // When the argument provided and a file exists by the provided filename:
        // count all words in the given file and print the most common
        // ("cat", "CAT", "cat," "cat." are different words)
        // Handle exception if the argument is not a file.
        // For i.e.: getMostCommonWord("test.txt");
        // Should return:
        // In
    }
    public static String getMostCommonWord(String fileName){
        List<String> lines = readFile(fileName);
        String text = String.join(" ", lines);
        String[] words = text.split(" ");
        Map<String, Integer> wordCounts = new HashMap<>();
        for (String word:words) {
            if (!wordCounts.containsKey(word))
                wordCounts.put(word, 1);
            else
                wordCounts.put(word, wordCounts.get(word) + 1);
        }
        int mostCommonWordCount = 0;
        for (Integer max : wordCounts.values()) {
            if (max > mostCommonWordCount) {
                mostCommonWordCount = max;
            }
        }
        for (Object word:wordCounts.keySet()) {
            if (wordCounts.get(word).equals(mostCommonWordCount)) {
                return (String) word;
            }
        }
        return null;
}

    private static List<String> readFile(String fileName) {
        List<String> lines = new ArrayList<>();
        try {
            Path filePath = Paths.get("C:\\green-fox\\week-05\\day-01\\MostCommonWord\\" + fileName);
            lines = Files.readAllLines(filePath);
        } catch (IOException e) {
            System.out.println("Argument not a file, please try again later.");
        }
        return lines;
    }


   /* public static int getMostCommonWordtrial(String fileName) {
        int count = 0;
        try {
            Map<String, Integer> wordCounts = new HashMap<>();
            List<String> lines = Files.readAllLines(Paths.get(fileName + ".csv"));

            for (String line : lines) {
                String[] lineParts = line.split(" ");

                for (String s : list) {
                    Integer c = stringsCount.get(s);
                    if (c == null) c = new Integer(0);
                    c++;
                    stringsCount.put(s, c);
                }
            }

            Map.Entry<String, Integer> mostRepeated = null;
            for (Map.Entry<String, Integer> e : stringsCount.entrySet()) {
                if (mostRepeated == null || mostRepeated.getValue() < e.getValue())
                    mostRepeated = e;
            }

            if (mostRepeated != null)
                System.out.println(mostRepeated.getKey());
        } catch (IOException e) {
            System.out.println("This argument is not a file, try it again!");
        }


        private static String removePunctuation (String string){
            return string.replaceAll("[\\.,:;\\-\\(\\)\\{\\}\\[\\]!?\\\"\\']+", "");
        }*/
    }