#include <iostream>
#include <vector>

using namespace std;

int compta_tires (int n, vector<int>& sol_parcial, int idx) {
  if (idx == int(sol_parcial.size())) {
    return 1;
  }
  else {
    sol_parcial[idx] = 0;
    int res = compta_tires(n,sol_parcial,idx+1);
    
    sol_parcial[idx] = 1;
    res += compta_tires(n,sol_parcial,idx+1);
    return res;
  }
}

int compta_tires (int n) {
  vector<int> sol_parcial(n);
  int idx = 0;
  return compta_tires(n,sol_parcial,idx);
}

int main () {
  int n;
  cin >> n;
  cout << compta_tires(n) << endl;
}
