/* File: clcs_fast.cpp
 * Date: 06/01/14
 * -------------------
 * oh CS 161
 * it rhymes with fun boba run
 * but it is not fun
 */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// Constants.
const int MAX_WORD_LEN = 2048;

// Global arrays.
int AB[2 * MAX_WORD_LEN][MAX_WORD_LEN];
int starts[MAX_WORD_LEN][MAX_WORD_LEN];
int ends[MAX_WORD_LEN][MAX_WORD_LEN];
int bds[MAX_WORD_LEN][2];
int curr_clcs;

string A, B;

int LCS() {
  int m = A.length(), n = B.length();
  int i, j;
  for (i = 0; i <= m; i++) AB[i][0] = 0;
  for (j = 0; j <= n; j++) AB[0][j] = 0;
  
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      AB[i][j] = max(AB[i-1][j], AB[i][j-1]);
      if (A[i-1] == B[j-1]) AB[i][j] = max(AB[i][j], AB[i-1][j-1]+1);
    }
  }
  
  return AB[m][n];

}

bool IsUpValid(int path, int r, int c) {

  return AB[r - 1][c] == val && !()

}

bool IsLeftValid(int path, int r, int c) {



}

void BackTrace(int path, int r_end, int c_end) {

  int r = r_end;
  int c = c_end;
  int val = AB[r_end][c_end];

  while (r != r_end - A.length() && c != c_end - B.length()) {

    // BE CAREFUL ABOUT DIAGONALS DEPENDING ON WHETHER CHECKING 
    // UPPER BOUND OR LOWER BOUND

    if (IsUpValid(path, r, c)) {

    } else if (IsLeftValid(path, r, c)) {

    } else {
      // go diagonal
    }

  }





    // check boundaries
    // check which direction to go, prioritize up first then left, otherwise diag
    // if hit top of subproblem array, decrement left
    // if hit left of subproblem array, decrement up

    // if (n == stopx) m--;
    //  else if (arr[m][n - 1] == init) n--;
    //  else if (arr[m - 1][n] == init) m--;
    //  else {
    //    m--; n--;
    //  }
    // }

}

void InitPathBounds() {
  // do stuff with path_bds
}

int main() {
  int num_test_case_idx;
  cin >> num_test_case_idx;
  for (int case_idx = 0; case_idx < num_test_case_idxs; case_idx++) {

    InitPathBounds();
    curr_clcs = 0;

    cin >> A >> B;
    cout << LCS() << endl;
  }
  return 0;
}

