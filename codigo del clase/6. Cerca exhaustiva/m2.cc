#include <iostream>
#include <vector>

using namespace std;

pair<int,vector<bool>> knapsack (int n, int W, const vector<int>& pes, const vector<int>& valor,
				 vector<bool>& sol, int idx, int p) {
  if (idx == n) {
    if (p > W) return {-1,sol};
      
    int v = 0;
    for (int i = 0; i < n; ++i)
      if (sol[i]) v += valor[i];
    
    return {v,sol};
  }
  else {
    sol[idx] = false;
    pair<int,vector<bool>> s1 = knapsack(n,W,pes,valor,sol,idx+1,p);

    sol[idx] = true;
    pair<int,vector<bool>> s2 = knapsack(n,W,pes,valor,sol,idx+1,p + pes[idx]);

    if (s1.first > s2.first) return s1;
    else return s2;
  }

}

pair<int,vector<bool>> knapsack (int n, int W, const vector<int>& pes, const vector<int>& valor) {
  vector<bool> sol(n);
  int idx = 0;
  int p = 0;
  return knapsack(n,W,pes,valor,sol,idx,p);
}


int main () {
  int n;
  cin >> n;

  vector<int> pes(n), valor(n);
  for (int i = 0; i < n; ++i) cin >> pes[i] >> valor[i];

  int W; cin >> W;
  
  pair<int,vector<bool>> sol = knapsack(n,W,pes,valor);

  cout << "Valor " << sol.first << endl;
  cout << "Escullo: ";
  for (uint i = 0; i < sol.second.size(); ++i)
    if (sol.second[i]) cout << i << " ";
  cout << endl;
}
