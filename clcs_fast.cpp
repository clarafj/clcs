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
<<<<<<< HEAD
vector< vector<int> > finish;
// NOTE: "ends" was ambiguous because it is a function for 
//    other things (i.e. string manipulations)

=======
vector< vector<int> > ends;
>>>>>>> 7d1604a9aa5d660f9922cd538139311cacdcaf65
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
<<<<<<< HEAD
=======

>>>>>>> 7d1604a9aa5d660f9922cd538139311cacdcaf65
}

bool IsUpValid(int path, int val, int r, int c) {

  // Conditions on current point:
  //
  // 1. The upper point has the same value as the current point.
  // 2. It is not true that the current point is not on the upper boundary path, but 
  //     the upper point is not on the upper boundary path 
  //     (i.e., not crossing the upper boundary path).

<<<<<<< HEAD
  return AAB[r - 1][c] == val &&
    !(c >= starts[bds[path][1]][r] && c <= finish[bds[path][1]][r] && 
      !(c >= starts[bds[path][1]][r - 1] && c <= finish[bds[path][1]][r - 1]));
=======
  return AAB[r - 1][c] == val && 
    !(c >= starts[bds[path][1]][r] && c <= ends[bds[path][1]][r] && 
      !(c >= starts[bds[path][1]][r - 1] && c <= ends[bds[path][1]][r - 1]));
>>>>>>> 7d1604a9aa5d660f9922cd538139311cacdcaf65

}

bool IsLeftValid(int path, int val, int r, int c) {

  // Conditions on current point:
  //
  // 1. The left point has the same value as the current point.
  // 2. It is not true that the current point is not on the lower boundary path, but 
  //     the left point is not on the lower boundary path 
  //     (i.e., not crossing the lower boundary path).

  return AAB[r][c - 1] == val && 
<<<<<<< HEAD
    !(c >= starts[bds[path][0]][r] && c <= finish[bds[path][0]][r] && 
      !((c - 1) >= starts[bds[path][0]][r] && (c - 1) <= finish[bds[path][0]][r]));
=======
    !(c >= starts[bds[path][0]][r] && c <= ends[bds[path][0]][r] && 
      !((c - 1) >= starts[bds[path][0]][r] && (c - 1) <= ends[bds[path][0]][r]));
>>>>>>> 7d1604a9aa5d660f9922cd538139311cacdcaf65

}

void BackTrace(int path) {

  int r = path + A.length();
  int c = B.length();
  int val = AAB[r][c];
  starts[path][r] = c;
  finish[path][r] = c;
  int num_diags = 0;

  while (r != path && c != 0) {

    if (r == path) c--; 
    else if (c == 0) r--;
    else if (IsUpValid(path, val, r, c)) {

      r--;
      finish[path][r] = c;

    } else if (IsLeftValid(path, val, r, c)) {

      c--;
      starts[path][r] = c;
      // WHAT IF THE CURRENT ROW IS LESS THAN THE PATH INDEX OF THE LOWER BOUND PATH
      // I.E. HOW TO FILL IN STARTS/finish FOR ROW INDICES LESS THAN THE CURRENT PATH

    } else if (AAB[r - 1][c - 1] == val - 1) {

      r--;
      c--;
      starts[path][r] = c;
      finish[path][r] = c;
      num_diags++;

    } else cerr << "BACKTRACE CHECKS OR ARRAY FILLING INCORRECT" << endl;

  }

  // If number of diagonals in the backtrace is greater, update the CLCS.
  if (num_diags > curr_clcs) curr_clcs = num_diags;

}

<<<<<<< HEAD
void InitStartsfinish() {

  AAB.resize(2 * A.length());
  starts.resize(A.length());
  finish.resize(A.length());
=======
void InitStartsEnds() {

  AAB.resize(2 * A.length());
  starts.resize(A.length());
  ends.resize(A.length());
>>>>>>> 7d1604a9aa5d660f9922cd538139311cacdcaf65
  bds.resize(A.length());

  for (int i = 0; i < A.length(); ++i) {
    AAB[i].resize(B.length(), 0);
    starts[i].resize(A.length(), 0);
<<<<<<< HEAD
    finish[i].resize(A.length(), 0);
    // Is the resize of the bds vector really necessary?
    // bds.resize(2, 0);
=======
    ends[i].resize(A.length(), 0);
    bds.resize(2, 0);
>>>>>>> 7d1604a9aa5d660f9922cd538139311cacdcaf65
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

<<<<<<< HEAD
//     InitStartsfinish();
=======
//     InitStartsEnds();
>>>>>>> 7d1604a9aa5d660f9922cd538139311cacdcaf65

//     InitPathBounds();
//     curr_clcs = 0;

//     cin >> A >> B;
//     cout << LCS() << endl;
//   }
//   return 0;
// }

