#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int k_esim(int k, const VVI& V) {
    map <int, pair<int, int>> nums;
    for (int i = 0; i < V.size(); i++)
        if(not V[i].empty()) nums[V[i][0]] = make_pair(i, 0);
    
    // for (const auto&it : nums) {
    //     cout << it.first << endl;
    //     cout << it.second.first << endl;
    //     cout << it.second.second << endl;
    // }


    while (1 < k) {
        pair<int, int> min = nums.begin()->second;

        // cout << min.first << endl;
        // cout << min.second << endl;
        // cout << "--" << endl;
        
        nums.erase(nums.begin());
        if (V[min.first].size() > ++min.second) {                
                nums[V[min.first][min.second]] = make_pair(min.first, min.second);
                cout << V[min.first][min.second] << endl;
            }
        --k;
    }

    return nums.begin()->first;
}

int main () {
    int n;
    cin >> n;
    VVI V(n);

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
        int num;
        cin >> num;
        V[i].push_back(num);
        }
    }

    int k;
    cin >> k;
    cout << k_esim(k, V) << endl;
} 