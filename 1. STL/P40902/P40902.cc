#include <iostream>
#include <map>

using namespace std;

int main () {
    string player, command;
    map<string, int>Casino;
    
    while (cin >> player >> command) {
        auto it = Casino.find(player);
        if (command == "enters") {
            if(it == Casino.end()) {
                Casino.insert({player, 0});
            } else {
                cout << player << " is already in the casino" << endl;
            }
        } else if (command == "wins") {
            int gain;
            cin >> gain;
            if(it != Casino.end()) {
                (it->second) += gain;
            } else {
                cout << player << " is not in the casino" << endl;
            }
        } else if (command == "leaves") {
            if (it != Casino.end()) {
                cout << it->first << " has won " << it->second << endl;
                Casino.erase(it->first);
            } else {
                cout << player << " is not in the casino" << endl;
            }
        }
    };

    cout << "----------" << endl;
    for (const auto &it: Casino) {
        string name = it.first;
        cout << it.first << " is winning " << it.second << endl;
    }
}