#include <iostream>
#include <vector>

using namespace std;

int modP(int n, int k, int m) {
    // caso base
    if (k == 0) return 1;
    else if (n == 0) return 0;
    else {
        int res;
        // if n even then we do n^k mod m == [(n^(k/2)) * (n^(k/2))] mod m;
        if (k % 2 == 0) {
            res = modP(n, k/2 , m); // n^(k/2)
            res = res * res % m; 
        } else {
        // if n odd then we do n^k mod m == [(n * (n^(k-1))] mod m == n mod * (n^(k-1)) mod;
            res = (n * modP(n, k - 1, m)) % m; 
        }

        return res;
    }
}

int main () {
    // vals
    int n, k, m;
    while (cin >> n >> k >> m) {
        cout << modP(n, k, m) << endl;
    };
} 