#include <iostream>
#include <vector>

using namespace std;

long int escriu_quadrats (int n, vector<vector<int>>& q,
			  int i, int j,
			  vector<vector<bool>>& vf,
			  vector<vector<bool>>& vc
			  ) {
  if (j == n) return escriu_quadrats(n,q,i+1,0,vf,vc);
  
  if (i == n) return 1;
  else {
    long int res = 0;
    for (int k = 0; k < n; ++k) {
      if (not vf[k][i] and not vc[k][j]){
	q[i][j] = k;
	vf[k][i] = true; vc[k][j] = true;
	res += escriu_quadrats(n,q,i,j+1,vf,vc);
	vf[k][i] = false; vc[k][j] = false;
      }
    }
    return res;
  }
}

long int escriu_quadrats (int n) {
  vector<vector<int>> q(n,vector<int>(n));
  vector<vector<bool>> vf(n,vector<bool>(n,false));
  vector<vector<bool>> vc(n,vector<bool>(n,false));
  int i = 0, j = 0;
  return escriu_quadrats(n,q,i,j,vf,vc);
}

int main () {
  int n;
  cin >> n;
  cout << escriu_quadrats(n) << endl;
}
