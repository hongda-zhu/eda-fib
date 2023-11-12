#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator () (const string& a, const string& b) const {
        if (a.length() < b.length()) return true;
        else if (a.length() > b.length()) return false;
        else return a < b;
    }
};

void print (set <string>&S_HAS, set <string, cmp>& S_HAD, int&counter, bool quit) {
        cout << "GAME #" << counter << endl;
        // HAS:
        cout << "HAS:" << endl;
        for (const auto &elem: S_HAS) cout << elem << endl; 
        cout << endl;

        // HAD
        cout << "HAD:" << endl;
        for (const auto &elem: S_HAD) cout << elem << endl;
        if (not quit) cout << endl;

        // RESET
        ++counter;
        S_HAS.clear();
        S_HAD.clear();
}

int main () {
    set<string> S_HAS; // set of words -> HAS:
    set<string, cmp> S_HAD; // set of words -> HAD; (set of words that has been in S but finally are not in S )
    string w; // word
    int counter = 1;
    while (cin >> w && w != "QUIT") {
        if (w == "END") print(S_HAS, S_HAD, counter, false);
        else {
            // case while the word's not exist in the S_HAS
            if (S_HAS.find(w) == S_HAS.end()) {
                S_HAS.insert(w); 
                if(S_HAD.find(w) != S_HAD.end()) S_HAD.erase(w);
            } else {
            // case while the word's exist in the S_HAS 
                S_HAS.erase(w);
                if(S_HAD.find(w) == S_HAD.end()) S_HAD.insert(w);
            }
        }
    }
    print(S_HAS, S_HAD, counter, true);
}