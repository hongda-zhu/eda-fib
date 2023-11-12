#include <iostream>
#include <iomanip>
#include <set>
#include <string>
using namespace std;

void stats(const multiset<int>& M) {
    if (not M.empty()) {
    auto it_min = M.begin();
    auto it_max = M.rbegin();
    double sum = 0;
    for (const auto& elem: M) {
        sum += elem;
    }   
        cout << "minimum: " << (*it_min) << ", maximum: " << (*it_max) << ", average: " << sum/M.size() << endl;
    } else cout << "no elements" << endl;
}

int main () {
    multiset<int> M;
    string op;
    cout << fixed << setprecision(4);
    while (cin >> op) {
        if (op == "number") {
            int n;
            cin >> n;
            M.insert(n);
        } else if ("delete") {
            if(not M.empty())
            M.erase(M.begin());
        }
        stats(M);
    }
} 