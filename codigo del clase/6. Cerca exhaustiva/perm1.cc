#include <iostream>
#include <vector>

using namespace std;

void escriu_permutacions (int n, vector<int>& sol_parcial, int idx) {
  if (idx == n) {
    for (int x : sol_parcial) cout << x << " ";
    cout << endl;
  }
  else {
    for (int k = 1; k <= n; ++k) {
      // si no he usat k fins ara
      bool usat = false;
      for (int i = 0; not usat and i < idx; ++i)
	usat = (sol_parcial[i] == k);
      if (not usat) {
	sol_parcial[idx] = k;
	escriu_permutacions(n,sol_parcial,idx+1);
      }
    }
  }
}

void escriu_permutacions (int n) {
  vector<int> sol_parcial(n);
  int idx = 0;
  escriu_permutacions(n,sol_parcial,idx);
}

int main ( ){
  int n;
  cin >> n;
  escriu_permutacions(n);
}
