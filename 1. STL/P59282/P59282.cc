#include <iostream>
#include <queue>
#include <string>
using namespace std;

void print_stats(int min, int max, double total, int counter) {
    cout.setf(ios::fixed);
    cout.precision(4);
    cout << "minimum: " << (min) << ", maximum: " << (max) << ", average: " << total/counter << endl;
}

int main () {
    // create a min-heap from the smallest elements to the largest elements. 
    priority_queue<int, vector<int>, greater<int>> PQ;
    string op;
    bool first = true;
    int max = 0, min = 0, counter = 0;
    double total = 0;
    while (cin >> op) {
        if (op == "number") {
            int val; 
            cin >> val;
            PQ.push(val);
            if (first) {
                max = val;
                min = val;
                total = val;
                first = false;
                ++counter;
            } else 
            {
                if (val > max) max = val; 
                min = PQ.top();
                total += val;
                ++counter;
            }
            print_stats(min, max ,total, counter);
        } else if (op == "delete") {
            if (!PQ.empty()) { 
                total -= PQ.top();
                PQ.pop();
                --counter;
                min = PQ.top();
                if (PQ.empty()) first = true;
            } 
            
            if(PQ.empty()) cout << "no elements" << endl; 
            else print_stats(min, max,total, counter); 
        }
    } 
    return 0;
}