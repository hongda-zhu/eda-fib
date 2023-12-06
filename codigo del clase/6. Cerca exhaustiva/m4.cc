#include <iostream>
#include <vector>

using namespace std;


int bv = -1; // best value
vector<bool> bs; // best solution found so far

void knapsack (int n, int W, const vector<int>& pes, const vector<int>& valor,
	       vector<bool>& sol, int idx, int p, int v) {

  if (p > W) return;
  
  if (idx == n) {
    if (v > bv) {
      bv = v;
      bs = sol;
    }
    return;
  }
  else {
    sol[idx] = false;
    knapsack(n,W,pes,valor,sol,idx+1,p,v);

    sol[idx] = true;
    knapsack(n,W,pes,valor,sol,idx+1,p + pes[idx],v + valor[idx]);
  }

}

void knapsack (int n, int W, const vector<int>& pes, const vector<int>& valor) {
  vector<bool> sol(n);
  int idx = 0;
  int p = 0, v = 0;
  knapsack(n,W,pes,valor,sol,idx,p,v);  
}


int main () {
  int n;
  cin >> n;

  vector<int> pes(n), valor(n);
  for (int i = 0; i < n; ++i) cin >> pes[i] >> valor[i];

  int W; cin >> W;
  
  knapsack(n,W,pes,valor);

  cout << "Valor " << bv << endl;
  cout << "Escullo: ";
  for (uint i = 0; i < bs.size(); ++i)
    if (bs[i]) cout << i << " ";
  cout << endl;
}
