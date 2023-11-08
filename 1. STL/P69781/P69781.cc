#include <iostream>
#include <map>
using namespace std;

#define LIMIT 100000000

int Collatz (int x, int y, int n) {
    if(n%2 == 0) {
        n = n/2 + x;
    } else {
        n = 3*n + y;
    }
    return n;
}

int main () {
    int x, y, n;
    while(cin >> x >> y >> n) {
        int pos = 1;
        map<int, int> M; // <pos, val>
        bool repeated = false;
        M[n] = 0;
        while(not repeated and n <= LIMIT) {
            n = Collatz(x, y, n);
            auto it = M.find(n);
            if (it == M.end()) {
                M[n] = pos;
                ++pos;
            } else {
                n = pos - M[n];
                repeated = true;            
            }
        }
        M.clear();
        cout << n << endl;
    };
} 