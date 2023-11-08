#include <iostream>
#include <map>
using namespace std;

int main () {
    map<string, int> Bag;
    string cmd;
    while(cin >> cmd) {
        if(cmd == "minimum?"){
            if(Bag.empty()) cout << "indefinite minimum" << endl;
            else {
                auto it = Bag.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        } else if (cmd == "maximum?") {
            if(Bag.empty()) cout << "indefinite maximum" << endl;
            else {
                auto it = Bag.rbegin();
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        } else if (cmd == "store") {
            string s;
            cin >> s;
            auto it = Bag.find(s);
            if (it != Bag.end()) 
                ++(it->second);
            else {
                Bag[s] = 1;
            }
        } else if (cmd == "delete") {
            string s;
            cin >> s;
            auto it = Bag.find(s);
            if(it->second <= 1) Bag.erase(s);
            else --(it->second);
        }
    }
} 