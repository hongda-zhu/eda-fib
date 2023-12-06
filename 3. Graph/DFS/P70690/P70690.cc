#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef vector<char>COL;
typedef vector<COL>Matrix;
const vector<pair<int, int>> dirs= {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

Matrix read_matrix(int r, int c) {
    Matrix M(r, COL(c));
    for (int i = 0; i < r; ++i) 
        for (int j = 0; j < c; ++j)
            cin >> M[i][j];
    return M;
}

bool check_viable (Matrix& M, int r, int c) {
    return (r >= 0 && c >= 0 && M.size() > r && M[0].size() > c && M[r][c] != 'X');
}

bool read_via (Matrix& M, int r, int c) {
    if (M[r][c] == 'X') return false;
    if (M[r][c] == 't') return true;
    M[r][c] = 'X';
    for (auto d: dirs) {
        int temp_r = r + d.first;
        int temp_c = c + d.second;
        if (check_viable(M, temp_r, temp_c))
            if(read_via(M, temp_r, temp_c)) return true; // ?
    }
    return false;
}

int main () {
    int r, c;
    while(cin >> r >> c) { 
        Matrix M = read_matrix(r, c);
        
        int ini_r, ini_c;
        cin >> ini_r >> ini_c;

        int res = read_via(M, ini_r - 1, ini_c - 1);
        if (res) cout << "yes" << endl;
        else cout << "no" << endl;
    }

}   