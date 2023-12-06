#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

bool check_cycle (const VVE& G, int u, vector<bool>& vis, int prev) { 
    // as u == node present and prev == node previous
    // and we return bool cycle as result, we initialize the bool as false;
    bool cycle = false;
    if (vis[u]) cycle = true;
    else {
        // update current node
        vis[u] = true;

        // number of edges of the current node
        int m = G[u].size();
        
        for (int i = 0; i < m and not cycle; ++i) {
            // adjacency of current node
            int adj = G[u][i];
            // jump while we are visiting the other node of the adjacency
            if (adj != prev) cycle = check_cycle(G, adj, vis, u);
        }
    }
    return cycle;
}

int check_forest(const VVE& G) {
    int n = G.size();
    int res = 0;
    vector<bool> vis(n, false);
    bool cycle = false;
    for (int i = 0; i < n and not cycle; ++i) {
        // if node is visited, then this node is previous considered as a part of one of other trees that we have analyzed.
        if (not vis[i]) {
            // create a new tree from G[i], if there is not cycle, ++res;
            if (check_cycle(G, i, vis, -1)) cycle = true;
            else ++res;
        };
    }
    if (cycle) res = -1;
    return res;
}


int main () {
    int n, m;
    while (cin >> n >> m) {
        VVE G(n);
        int x, y;
        for (int i = 0; i < m; ++i ) {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        int res = check_forest(G);
        if (res != -1) cout << res << endl;
        else cout << "no" << endl;
    }
}   