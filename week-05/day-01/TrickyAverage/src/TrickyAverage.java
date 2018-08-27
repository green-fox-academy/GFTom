public class TrickyAverage {

    public static void main(String[] args) {
        int[] numbers = new int[]{6};

        System.out.println(getTrickyAvg(numbers));
    }

    public static double getTrickyAvg(int[] numbers) {
        double trickyAvg = 0;
        int smallestOdd = getSmallestOdd(numbers);
        int largestEven = getLargestEven(numbers);
        if (numbers.length < 1){
            return 0;
        }else if (smallestOdd == Integer.MAX_VALUE){
            trickyAvg = largestEven/2.;
        }else if (largestEven == Integer.MIN_VALUE){
            trickyAvg = smallestOdd/2.;
        }else{
        trickyAvg = (smallestOdd + largestEven) / 2.;
        }
        return trickyAvg;

    }

    public static int getSmallestOdd(int[] numbers) {
        int tempSmallestOdd = Integer.MAX_VALUE;
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] % 2 != 0 && numbers[i] < tempSmallestOdd) {
                tempSmallestOdd = numbers[i];
            }
        }
        return tempSmallestOdd;
    }

    public static int getLargestEven(int[] numbers) {
        int tempLargestEven = Integer.MIN_VALUE;
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] % 2 == 0 && numbers[i] > tempLargestEven) {
                tempLargestEven = numbers[i];
            }
        }
        return tempLargestEven;
    }
}
