#include <iostream>
#include <vector>

using namespace std;

void escriu_quadrats (int n, vector<vector<int>>& q,
		      int i, int j) {
  if (i == n) {
    // escriu 
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) cout << q[r][c] << " ";
      cout << endl;
    }
    cout << endl;
  }
  else {
    for (int k = 1; k <= n; ++k) {
      bool usat = false;
      for (int p = 0; not usat and p < j; ++p)
	usat = (q[i][p]== k);
      for (int p = 0; not usat and p < i; ++p)
	usat = (q[p][j]== k);      
      if (not usat){
	q[i][j] = k;
	int n_i, n_j;
	if (j == n-1) { n_i = i+1; n_j = 0;}
	else {n_i = i; n_j = j+1;}
	escriu_quadrats(n,q,n_i,n_j);
      }
    }
  }
}

void escriu_quadrats (int n) {
  vector<vector<int>> q(n,vector<int>(n));
  int i = 0, j = 0;
  escriu_quadrats(n,q,i,j);
}

int main () {
  int n;
  cin >> n;
  escriu_quadrats(n);
}
