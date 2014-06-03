/* File: clcs_fast.cpp
 * Date: 06/01/14
 * Clara Fannjiang (clarafj, 05787501)
 * John Louie (jwlouie, 0581386)
 * ------------------------------
 * oh CS 161
 * it rhymes with fun boba run
 * but it is not fun
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constants.
const int MAX_WORD_LEN = 2048;

// Global arrays.
vector< vector<int> > AAB;
vector< vector<int> > starts;
vector< vector<int> > ends;
// 0-th entry gives the lower bound path index; 1-st entry
// gives the upper bound path index.
vector< vector<int> > bds;
int curr_clcs;

string A, B;

int LCS() {
  int m = A.length(), n = B.length();
  int i, j;
  for (i = 0; i <= m; i++) AAB[i][0] = 0;
  for (j = 0; j <= n; j++) AAB[0][j] = 0;
  
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      AAB[i][j] = max(AAB[i-1][j], AAB[i][j-1]);
      if (A[i-1] == B[j-1]) AAB[i][j] = max(AAB[i][j], AAB[i-1][j-1]+1);
    }
  }
  
  return AAB[m][n];

}

bool IsUpValid(int path, int r, int c) {

  // Conditions on current point:
  //
  // 1. The upper point has the same value as the current point.
  // 2. It is not true that the current point is not on the upper boundary path, but 
  //     the upper point is not on the upper boundary path 
  //     (i.e., not crossing the upper boundary path).

  return AAB[r - 1][c] == val && 
    !(c >= starts[bds[path][1]][r] && c <= ends[bds[path][1]][r] && 
      !(c >= starts[bds[path][1]][r - 1] && c <= ends[bds[path][1]][r - 1]));

}

bool IsLeftValid(int path, int r, int c) {

  // Conditions on current point:
  //
  // 1. The left point has the same value as the current point.
  // 2. It is not true that the current point is not on the lower boundary path, but 
  //     the left point is not on the lower boundary path 
  //     (i.e., not crossing the lower boundary path).

  return AAB[r][c - 1] == val && 
    !(c >= starts[bds[path][0]][r] && c <= ends[bds[path][0]][r] && 
      !((c - 1) >= starts[bds[path][0]][r] && (c - 1) <= ends[bds[path][0]][r]));

}

void BackTrace(int path) {

  int r = path + A.length();
  int c = B.length();
  int val = AAB[r][c];
  starts[path][r] = c;
  ends[path][r] = c;
  int num_diags = 0;

  while (r != path && c != 0) {

    if (r == path) c--; 
    else if (c == 0) r--;
    else if (IsUpValid(path, r, c)) {

      r--;
      ends[path][r] = c;

    } else if (IsLeftValid(path, r, c)) {

      c--;
      starts[path][r] = c;
      // WHAT IF THE CURRENT ROW IS LESS THAN THE PATH INDEX OF THE LOWER BOUND PATH
      // I.E. HOW TO FILL IN STARTS/ENDS FOR ROW INDICES LESS THAN THE CURRENT PATH

    } else if (AAB[r - 1][c - 1] == val - 1) {

      r--;
      c--;
      starts[path][r] = c;
      ends[path][r] = c;
      diags++;

    } else cerr << "BACKTRACE CHECKS OR ARRAY FILLING INCORRECT" << endl;

  }

  // If number of diagonals in the backtrace is greater, update the CLCS.
  if (num_diags > curr_clcs) curr_clcs = num_diags;

}

void InitStartsEnds() {

  AAB.resize(2 * A.length());
  starts.resize(A.length());
  ends.resize(A.length());
  bds.resize(A.length());

  for (int i = 0; i < A.length(); ++i) {
    AAB[i].resize(B.length(), 0);
    starts[i].resize(A.length(), 0);
    ends[i].resize(A.length(), 0);
    bds.resize(2, 0);
  }

}

void InitPathBounds() {
  // do stuff to path bounds
}

int main() {


  return 0;

}

// int main() {
//   int num_test_case_idx;
//   cin >> num_test_case_idx;
//   for (int case_idx = 0; case_idx < num_test_case_idxs; case_idx++) {

//     InitStartsEnds();

//     InitPathBounds();
//     curr_clcs = 0;

//     cin >> A >> B;
//     cout << LCS() << endl;
//   }
//   return 0;
// }

