#include <iostream>
#include <vector>

using namespace std;

bool i_resistant_search(double x, const vector <double> &v, int l, int r) {
	if (l > r) return false;
	int mid = (l + r)/2;
	if (v[mid] == x) return true;
	else if (mid > 0 and v[mid-1] == x) return true;
	else if (mid < v.size() -1 and v[mid+1] == x) return true;
    else if (v[mid] < x) return i_resistant_search(x, v, mid + 1, r);
    else if (v[mid] > x) return i_resistant_search(x, v, l , mid - 1);
}

bool resistant_search(double x, const vector<double>& v) {
	return i_resistant_search(x,v,0,v.size()-1);
}

int main () {
    // Target
    double x;
    cin >> x;

    // V
    int n;
    cin >> n;
    vector<double> V(n);
    for (int l = 0; l < V.size(); ++l) cin >> V[l];

    // call
    cout << resistant_search(x,V) << endl;
} 