#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main () { 
    priority_queue<int> pq;
    char letter;
    while (cin >> letter) {
        
        if (letter == 'S') {
            int x;
            cin >> x;
            pq.push(x);
        } else if (letter == 'A') {
            if(pq.empty()) cout << "error!" << endl; 
            // return the first and biggest number that exist in the queue
            else cout << pq.top() << endl;
        } else if (letter == 'R') {
            // remove the first number of the queue
            if(pq.empty()) cout << "error!" << endl; 
            else pq.pop();
        } else if (letter == 'I') {
            // increases the greatest number
            int n;
            cin >> n;
            if(pq.empty()) cout << "error!" << endl; 
            else {
                int bg = pq.top();
                bg += n;
                pq.pop();
                pq.push(bg);
            }
        } else if (letter == 'D') {
            int n;
            cin >> n;
            if(pq.empty()) cout << "error!" << endl;
            else {
                int bg = pq.top();
                bg -= n;
                pq.pop();
                pq.push(bg);
            }
        }
    }
}