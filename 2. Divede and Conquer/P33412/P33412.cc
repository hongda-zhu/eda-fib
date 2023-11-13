#include <iostream>
#include <vector>

using namespace std;

int i_first_ocurrence(double x, const vector<double>& V, int l, int r) {
    // caso 1: caso base que peta la recurrencia cuando l > r
    if (l > r) return -1;

    int mid = (l + r)  / 2;
    if (V[mid] == x) {
        int prev = i_first_ocurrence(x, V, l, mid - 1);
        if (prev != -1) return prev;
        else return mid;
    } else if (V[mid] >  x) return i_first_ocurrence(x, V, l, mid - 1);
    else return i_first_ocurrence(x, V, mid + 1, r);
}

int first_occurrence(double x, const vector<double>& v) {
    return i_first_ocurrence (x, v, 0, v.size() - 1);
}

int main () {
    // Target
    double x;
    cin >> x;

    // V
    int n;
    cin >> n;
    vector<double> V(n);
    for (int i = 0; i < V.size(); ++i) cin >> V[i];

    // call
    cout << first_occurrence(x, V) << endl;
} 