import java.util.*;

/*
 *
 *
 *
 */

public class CLCSslow {

  static int[][] arr = new int[2048][2048];
  static String A = "", B = "";

  static int CLCS() {

    int m = A.length(), n = B.length();

    ArrayList<Integer> values = new ArrayList<Integer>();

    for (int k = 0; k < m; k++) {

      String Aprime = A.substring(k) + A.substring(0, k);

      int i, j;
      for (i = 0; i <= m; i++) arr[i][0] = 0;
      for (j = 0; j <= n; j++) arr[0][j] = 0;
      
      for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
          arr[i][j] = Math.max(arr[i-1][j], arr[i][j-1]);
          if (Aprime.charAt(i-1) == B.charAt(j-1)) arr[i][j] = Math.max(arr[i][j], arr[i-1][j-1]+1);
        }
      }

      values.add(arr[m][n]);

    } 

    return Collections.max(values);

  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int T = s.nextInt();
    for (int tc = 0; tc < T; tc++) {
      A = s.next();
      B = s.next();
      System.out.println(CLCS());
    }
  }
}
