#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

bool dfs_color (const VVE& G, VE& vis, VE& color, int u) {
    // u: vertex that we are working now
    
    for (int v: G[u]) {
        // v: one of the list of "arista/edge vertex" of the u node
        if(not vis[v]) {
            // mark the edge vertex visited
            vis[v] = true;

            // print the color for the edge vertex
            // from 0 to 1 or from 1 to 0
            color[v] = not color[u]; 

            // print recursively the color of subtree, and if the subtree rooted at vertex v is not bipartite, return false
            if (not dfs_color(G, vis, color, v)) return false;
        } else if (color[v] == color[u]) return false;
    }

    return true;
}

void is_bipartite (const VVE& G) {
    int n = G.size();
    VE vis (n, 0); // vis = 0 || 1; default not vis "0" for all nodes
    VE color (n, -1); // color = 0 || 1; default no "-1" color for all nodes

    if (n > 1) vis[0] = 1;
    color[0] = 0;
    bool col = false;

    for (int u = 0; u < n and not col; ++u) {
        if(not vis[u]) 
            if(dfs_color(G, vis, color, u)) col = true;
    };

    if(col) cout << "yes" << endl;
    else cout << "no" << endl;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        VVE G (n);
        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        is_bipartite(G);
    }
}   

#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <math.h>

using namespace std;

typedef vector<int> VE;
typedef list<int> LT;
typedef vector<LT> VVE;

void is_bipartite (const VVE& G) {
    int n = G.size();
    stack<int> S;
    VE vis(n, 0);
    VE color(n, -1);

    // initialize
    color[0] = 0;
    bool col = true;

    for (int u = 0; u < n and col; ++u) {
        if (not vis[u]) {
            S.push(u);
            vis[u] = 1;
            while (not S.empty() and col) {
                int v = S.top(); 
                S.pop();
                if (not vis[v]) {
                    vis[v] = 1;
                    color[v] = !color[u];
                    for(int w: G[v]) {
                        S.push(w);
                    }
                } else if (color[v] == color[u]) col = false;
            }
        }
    }
    
    if(col) cout << "yes" << endl;
    else cout << "no" << endl;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        VVE G (n);
        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        is_bipartite(G);
    }
}   