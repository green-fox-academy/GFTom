public class Matrix {
  public static void main(String[] args) {
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    int[][] matrix;
    matrix = new int[4][4];
    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix.length; j++) {
        if (i == j){
          matrix [i][j] = 1;
        } else {
          matrix [i][j] = 0;
        }
        System.out.print(matrix[i][j] + " ");
      }
      System.out.println();
    }
  }
}
