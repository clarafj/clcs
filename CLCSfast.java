import java.util.*;

/* 
 * 
 * 
 * 
 */

public class CLCSfast {

  static int[][] arr = new int[4096][2048]; //Double the x coordinate size in order to account for a potentially larger input size
  static String A = "", B = "";

  static class Point {
    int x;
    int y;

    public Point(int x, int y) {
      this.x = x;
      this.y = y;
    }

    public int x() {
      return x;
    }

    public int y() {
      return y;
    }
  }

  static ArrayList<Point> LCS() {
    int m = A.length() / 2, n = B.length();
    int i, j;
    for (i = 0; i <= m; i++) arr[i][0] = 0;
    for (j = 0; j <= n; j++) arr[0][j] = 0;
    
    for (i = 1; i <= m; i++) {
      for (j = 1; j <= n; j++) {
        arr[i][j] = Math.max(arr[i-1][j], arr[i][j-1]);
        if (A.charAt(i-1) == B.charAt(j-1)) arr[i][j] = Math.max(arr[i][j], arr[i-1][j-1]+1);
      }
    }

    return TraversePath(m, n, 0, 0);

  }

  static ArrayList<Point> TraversePath(int m, int n, int stopx, int stopy) {
    int init = arr[m][n];
    ArrayList<Point> path =  new ArrayList<Point>();
    path.add(new Point(m, n));
    while(m != stopx && n != stopy) {
      if (n == stopx) m--;
      else if (arr[m][n - 1] == init) n--;
      else if (arr[m - 1][n] == init) m--;
      else {
        m--; n--;
      }
      path.add(new Point(m, n));
      init = arr[m][n];
    }
    path.add(new Point(stopx, stopy));
    return path;

  }

  static void printPath(ArrayList<Point> path){
    for (Point p : path) {
      System.out.println("X = row coordinate: " + p.x() + " || Y = column coordinate: " + p.y());
      System.out.println("");
    }
  }

  static int CLCS() {

    ArrayList<Point> path0 = new ArrayList<Point>();

    path0 = LCS();

    FindShortestPath(A, B, path0, 0, A.length());

    printPath(path0);

    return 0;

  }

  static int FindShortestPath(String A, String B, ArrayList<Point> path, int pL, int pU) {
    return 0;
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int T = s.nextInt();
    for (int tc = 0; tc < T; tc++) {
      A = s.next();
      A = A + A; //Doubling the size of the string to make the double DP table
      B = s.next();
      System.out.println(CLCS());
    }
  }
}
