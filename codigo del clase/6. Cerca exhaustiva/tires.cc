#include <iostream>
#include <vector>

using namespace std;

void escriu_tires (int n, vector<int>& sol_parcial, int idx) {
  if (idx == int(sol_parcial.size())) {
    for (int x : sol_parcial) cout << x << " ";
    cout << endl;
  }
  else {
    sol_parcial[idx] = 0;
    escriu_tires(n,sol_parcial,idx+1);
    
    sol_parcial[idx] = 1;
    escriu_tires(n,sol_parcial,idx+1);
  }
}

void escriu_tires (int n) {
  vector<int> sol_parcial(n);
  int idx = 0;
  escriu_tires(n,sol_parcial,idx);
}

int main () {
  int n;
  cin >> n;
  escriu_tires(n);    
}
