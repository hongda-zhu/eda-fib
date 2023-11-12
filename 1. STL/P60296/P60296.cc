#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (const pair<int, string>&a, const pair<int,string>& b) {
    if(a.first > b.first) return true;
    else if (a.first == b.first) return b.second > a.second;
    else if (a.first < b.first) return false;
    else return false;
}

int main () {
    // <name, pair<points, connected>>
    map <string, pair<int, bool>> M;
    string op;
    string player;
    while (cin >> op >> player) {
        auto it = M.find(player);
        if (op == "LOGIN") {
            if (it == M.end()) {
                // insert an element directly (key and value at same time)
                M.insert(make_pair(player, make_pair(1200, true)));
            } else it->second.second = true;
        } else if (op == "LOGOUT") {
            if (it != M.end()) it->second.second = false;
        } else if (op == "PLAY") {
            string player2;
            cin >> player2;
            auto it2 = M.find(player2);
            if (it != M.end() && it2 != M.end() && it->second.second && it2->second.second) {
                it->second.first += 10;
                if ((it2->second.first > 1200)) it2->second.first -= 10;
            } else {
                cout << "player(s) not connected" << endl;
            }
        } else if (op == "GET_ELO") {
            if (it != M.end()) {
                cout << player << ' ' << it->second.first << endl;
            }
        }
    }

    cout << endl;
    cout << "RANKING" << endl;

    vector <pair <int, string>> Aux;
    for (auto & it :M) {
        Aux.push_back(make_pair(it.second.first, it.first));
    }

    sort(Aux.begin(), Aux.end(), comp);

    for(auto & it : Aux) {
        cout << it.second << " " << it.first << endl;
    }

    return 0;
} 