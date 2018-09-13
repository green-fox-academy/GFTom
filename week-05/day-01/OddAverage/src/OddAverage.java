import java.util.List;

public class OddAverage {
    public static void main(String[] args) {
        // Create a function called `oddAverage` that takes a list of numbers as parameter
        // and returns the average value of the odd numbers in the list
        // Create basic unit tests for it with at least 3 different test cases
        // 1 out of 3 has to be a negative test case.
    }
    public double oddAverage(List<Integer> numbers){
        int sumOdds =0;
        int countOdds = 0;
        if(numbers.size() == 0 || numbers == null){
           return 0;
        }
        for (int i = 0; i <numbers.size() ; i++) {
            if (numbers.get(i)%2 != 0){
                sumOdds = sumOdds + numbers.get(i);
                countOdds++;
            }
        }
        return sumOdds/countOdds;
    }

}
