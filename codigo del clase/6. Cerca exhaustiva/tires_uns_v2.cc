#include <iostream>
#include <vector>

using namespace std;

void escriu_tires (int n, int k, vector<int>& sol_parcial, int uns, int zeros, int idx) {
  if (idx == int(sol_parcial.size())) {
    if (uns == k) {
      for (int x : sol_parcial) cout << x << " ";
      cout << endl;
    }
  }
  else {
    if (zeros < n - k) {
      sol_parcial[idx] = 0;
      escriu_tires(n,k,sol_parcial,uns,zeros+1,idx+1);
    }
      
    if (uns < k) {
      sol_parcial[idx] = 1;
      escriu_tires(n,k,sol_parcial,uns+1,zeros,idx+1);
    }
  }
}

void escriu_tires (int n, int k) {
  vector<int> sol_parcial(n);
  int idx = 0;
  int uns = 0;
  int zeros = 0;
  escriu_tires(n,k,sol_parcial,uns,zeros,idx);
}

int main () {
  int n, k;
  cin >> n >> k;
  escriu_tires(n,k);    
}
