#include <iostream>
#include <vector>

using namespace std;

long int escriu_quadrats (int n, vector<vector<int>>& q,
		      int i, int j) {
  if (i == n) return 1;
  else {
    long int res = 0;
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
	res += escriu_quadrats(n,q,n_i,n_j);
      }
    }
    return res;
  }
}

long int escriu_quadrats (int n) {
  vector<vector<int>> q(n,vector<int>(n));
  int i = 0, j = 0;
  return escriu_quadrats(n,q,i,j);
}

int main () {
  int n;
  cin >> n;
  cout << escriu_quadrats(n) << endl;
}
