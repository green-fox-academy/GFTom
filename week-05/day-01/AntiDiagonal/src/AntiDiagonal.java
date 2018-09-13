public class AntiDiagonal {

    public static void main(String[] args) {
        int[][] twoDimensionMatrix = new int[][]{{1,8,10},{5,6,2},{4,3,9}};

        System.out.println(getAntiDiagonalAvg(twoDimensionMatrix));
        System.out.println(getDiagonalAvg(twoDimensionMatrix));
        System.out.println(getMaxElementsAvg(twoDimensionMatrix));

    }
//int[][] twoDimensionMatrix = new int[][]{{1,1,1},{2,2,2},{3,3,3}};
    public static double getAntiDiagonalAvg(int[][] twoDimensionMatrix){
        int sumAntiDiagonal = 0;
        int countAntidiagonalElements = twoDimensionMatrix.length;
        for (int i = 0; i < twoDimensionMatrix.length; i++) {
            for (int j = 0; j < twoDimensionMatrix[i].length; j++) {
                if(j == twoDimensionMatrix[i].length - i - 1){
                    sumAntiDiagonal = sumAntiDiagonal + twoDimensionMatrix[i][j];
                }
            }
        }
        return sumAntiDiagonal/countAntidiagonalElements;
    }

    public static double getDiagonalAvg(int[][] twoDimensionMatrix){
        int sumDiagonal =0;
        int countDiagonalElements = twoDimensionMatrix.length;
        for (int i = 0; i < twoDimensionMatrix.length; i++) {
            sumDiagonal = sumDiagonal + twoDimensionMatrix[i][i];
        }
        return sumDiagonal/countDiagonalElements;
    }

    public static double getMaxElementsAvg(int[][] twoDimensionMatrix){
        int sumMaxElements = 0;
        for (int i = 0; i < twoDimensionMatrix.length; i++) {
            int tempMaxElement = 0;
            for (int j = 0; j < twoDimensionMatrix[i].length; j++) {
                if(twoDimensionMatrix[i][j] > tempMaxElement){
                    tempMaxElement = twoDimensionMatrix[i][j];
                }
            }
            sumMaxElements = sumMaxElements + tempMaxElement;
        }
        return sumMaxElements/twoDimensionMatrix.length;
    }
    /**
     * Create and test a method called `getAntiDiagonalAvg` that takes a multidimensional array (only integers)
     * which represents a square matrix, as a parameter and returns the average of the numbers in the anti diagonal.
     *  - write test for 2 different scenarios
     *
     * Example cases:
     * [
     *   [1, 2, 3],
     *   [3, 4, 6],
     *   [5, 2, 5]
     * ]
     * Should return 4, because (3 + 4 + 5) / 3 = 4.
     *
     * [
     *   [3, 5, 11, -2],
     *   [3, 1, 7, 4],
     *   [5, 0, 2, 9],
     *   [21, 7, 8, 2]
     * ]
     * Should return 6.5, because (-2 + 7 + 0 + 21) / 4 = 6.5.
     */
}
