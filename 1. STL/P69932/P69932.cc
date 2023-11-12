#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

int main () {
    string s;
    while (getline(cin, s)) {
        istringstream ss(s);
        int n;
        set<int> S;
        while(ss >> n) S.insert(n); 

        int prev = *(S.begin());
        int count = 1;
        if (S.empty()) count = 0;
        else {
            for (const auto& elem: S) {
                // condition: the resulting must be increasing
                // there cannot be two even numbers together nor two odd numbers together.
                if(elem > prev && ((elem % 2 == 0 and prev % 2 != 0) || (elem % 2 != 0 and prev % 2 == 0))) ++count;
                // iterate
                prev = elem;
            }
        }
        cout << count << endl;
    }
} 