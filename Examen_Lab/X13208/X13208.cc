#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cassert>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;
typedef pair<int,int> Vertex;

const int INF = numeric_limits<int>::max();
const vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

Matrix read_matrix(int n) {
    Matrix A(n, Row(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> A[i][j];
    }
    return A;
}

bool es_vora(const Vertex& u, int n) {
    return u.first == 0 or u.first == n - 1 or u.second == 0 or u.second == n - 1;
}

int mes_proper(const Matrix& M) {
    int n = M.size();
    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<bool>> tret(n, vector<bool>(n,false));
    priority_queue<pair<int,Vertex>,vector<pair<int,Vertex>>,greater<pair<int,Vertex>>> Q;

    Vertex origen = {n/2, n/2};
    dist[origen.first][origen.second] = M[origen.first][origen.second];
    Q.push({M[origen.first][origen.second],origen});
    while (not Q.empty()) {
        auto p = Q.top(); Q.pop();
        int d = p.first;
        Vertex u = p.second;

        // cout << "Trec (" << u.first << "," << u.second << ") que esta a distancia " << d << endl;

        // assert(d == dist[u.first][u.second]); aixÃ² ha de ser cert

        if(es_vora(u,n)) return d; //Si u es una casella de la vora --> return dist[u.first][u.second]
        
        if (not tret[u.first][u.second]) {
            tret[u.first][u.second] = true;
            for (auto dir: dirs) {
                Vertex v = {u.first + dir.first, u.second + dir.second};
                if(dist[v.first][v.second] > dist[u.first][u.second] + M[v.first][v.second]) {
                    dist[v.first][v.second] = dist[u.first][u.second] + M[v.first][v.second];
                    // cout << "afegeixo a la cua (" << v.first << "," << v.second << ") amb distancia " << dist[v.first][v.second] << endl;
                    Q.push({dist[v.first][v.second],v});
                }
            }
        }
    }
    return 11111;
}

int main() {
    int n;
    while (cin >> n) {
        Matrix M = read_matrix(n);
        cout << mes_proper(M) << endl;
    }
}