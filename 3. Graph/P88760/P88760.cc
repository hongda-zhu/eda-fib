#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

struct INFO {
    double x;
    double y;
    double r;
};

typedef vector<INFO> ROQUES;

bool handleJump (const INFO& a, const INFO& b, int d) {
    // distance > distance between two rocks == 
    // d > (raiz (x2 - x1) ^2 + (y2 - y1) ^2) - r1 -r2) 
    return d >= (sqrt(pow((b.x - a.x),2) + pow((b.y - a.y),2)) - a.r - b.r);
};

int BFS (const ROQUES& Rocks, double d) {
    int n = Rocks.size();
    vector<int>dist(n, -1);
    dist[0] = 0;
    queue<int> Q;
    Q.push(0);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < n; ++i) {
            if(dist[i] == -1 and handleJump(Rocks[u], Rocks[i], d)) {
                dist[i] = dist[u] + 1;
                Q.push(i);
                if(i == dist.size() - 1) return dist[i];
            }
        }
    }
    return -1;
}

int main () {
    int n;
    double d;
    while (cin >> n >> d) {
        // read size
        ROQUES Rocks(n);
        for (auto& rock: Rocks) cin >> rock.x >> rock.y >> rock.r;
        int res = BFS(Rocks, d);
        if (res != -1) cout << res << endl;
        else cout << "Xof!" << endl;
    }
}