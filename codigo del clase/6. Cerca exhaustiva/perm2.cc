#include <iostream>
#include <vector>

using namespace std;

int compta_permutacions (int n, vector<int>& sol_parcial, int idx, vector<bool>& usat) {
  if (idx == n) {
    return 1;
  }
  else {
    int res = 0;
    for (int k = 1; k <= n; ++k) {      
      if (not usat[k]) {
	sol_parcial[idx] = k;
	usat[k] = true;
	res += compta_permutacions(n,sol_parcial,idx+1,usat);
	usat[k] = false;
      }
    }
    return res;
  }
}

int compta_permutacions (int n) {
  vector<int> sol_parcial(n);
  vector<bool> usat(n+1,false);
  int idx = 0;
  return compta_permutacions(n,sol_parcial,idx,usat);
}

int main ( ){
  int n;
  cin >> n;
  cout << compta_permutacions(n) << endl;
}
