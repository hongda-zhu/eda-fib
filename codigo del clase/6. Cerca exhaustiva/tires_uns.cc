#include <iostream>
#include <vector>

using namespace std;

void escriu_tires (int n, int u, vector<int>& sol_parcial, int idx) {
  if (idx == int(sol_parcial.size())) {
    int c = 0;
    for (int x : sol_parcial) c += x;
    if (c == u) {
      for (int x : sol_parcial) cout << x << " ";
      cout << endl;
    }
  }
  else {
    sol_parcial[idx] = 0;
    escriu_tires(n,u,sol_parcial,idx+1);
    
    sol_parcial[idx] = 1;
    escriu_tires(n,u,sol_parcial,idx+1);
  }
}

void escriu_tires (int n, int u) {
  vector<int> sol_parcial(n);
  int idx = 0;
  escriu_tires(n,u,sol_parcial,idx);
}

int main () {
  int n, u;
  cin >> n >> u;
  escriu_tires(n,u);    
}
