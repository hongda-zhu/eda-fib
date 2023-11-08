#include <iostream>
#include <set>
using namespace std;

int main () {
    set<string> Seq;
    string s;
    auto median = Seq.begin();
    while(cin >> s and s != "END") {
        // set.insert(T).first == *it, refleja el valor de esa posición
        // si hacemos auto it = set.insert(T).first y *it, da lo mismo
        auto it = Seq.insert(s).first;
        // caso 1: cuando iniciamos el loop
        if(median == Seq.end()) median = it;
        else if (Seq.size()%2 == 0 and s < *median) --median;
        else if (Seq.size()%2 != 0 and s > *median) ++median;
        cout << *median << endl;
    }   
} 