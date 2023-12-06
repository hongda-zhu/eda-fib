#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef vector<char> VE;
typedef vector<VE>  VVE;

typedef vector<bool>CV;
typedef vector<CV> VCV;

typedef vector <pair<char, pair<int, int>>>  PV;

const vector <pair<int, int>> dirs = {{-1 ,0}, {0, -1}, {1, 0}, {0, 1}};

void dfs_paint(VVE& G, char c, int i, int j) {
    if (G[i][j] != '#') {
        G[i][j] = c;
    }
}

void dfs_paint(VVE& G, const PV& pos) {
    VCV vis (G.size(), CV(G[0].size()));
    for (int i = 0; i < pos.size(); ++i) {
        char c = pos[i].first;
        pair <int, int> position = pos[i].second;
        dfs_paint(G, c, position.first, position.second);
    }
}

int main () {
    int r, c;
    while (cin >> r >> c) {
        VVE G(r, VE(c));
        PV pos;
        
        for (int i = 0; i < r; i++) 
            for (int j = 0; j < c; j++) {
                cin >> G[i][j];
                if (G[i][j] != '#' or '.') pos.push_back(make_pair(G[i][j], make_pair(i, j)));
            }

        dfs_paint(G, pos);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) 
                cout << G[i][j];
            cout << endl;
        }

        cout << endl;
    }
}   