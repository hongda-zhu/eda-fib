#include <iostream>
#include <vector>

using namespace std;

int compta_permutacions (int n, vector<int>& sol_parcial, vector<bool>& usat) {
  if (sol_parcial.size() == n) {
    return 1;
  }
  else {
    int res = 0;
    for (int k = 1; k <= n; ++k) {      
      if (not usat[k]) {
	sol_parcial.push_back(k);	
	usat[k] = true;
	res += compta_permutacions(n,sol_parcial,usat);
	usat[k] = false;
	sol_parcial.pop_back();			  
      }
    }
    return res;
  }
}

int compta_permutacions (int n) {
  vector<int> sol_parcial;
  vector<bool> usat(n+1,false);
  return compta_permutacions(n,sol_parcial,usat);
}

int main ( ){
  int n;
  cin >> n;
  cout << compta_permutacions(n) << endl;
}
