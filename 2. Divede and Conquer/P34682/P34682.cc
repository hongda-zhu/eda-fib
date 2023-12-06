#include <iostream>
#include <vector>
using namespace std;


int fix_point(const vector <int> &S, int a, int l, int r) {
	if (l > r) return -1;
	int m = (l + r) / 2;
	if (S[m] + a == m) {
		int prev = fix_point(S, a, l, m-1);
		if(prev != -1) return prev;
		else return m;
	}
	if (S[m] + a > m) return fix_point(S, a, l, m-1);
	else if (S[m] + a <= m) return fix_point(S, a, m+1, r);
}

int main() {
	int n; 
	int seq_counter = 1;

	while (cin >> n) {
		cout << "Sequence #" << seq_counter << endl;
		vector<int> S (n + 1);
		for (int i = 1; i < n + 1; i++) cin >> S[i];

		int m;
		cin >> m;
		for (int i = 1; i <= m; i++) {
			int a;
			cin >> a;
			int exist_fp = fix_point(S, a, 1, n);
			if (exist_fp != -1) cout << "fixed point for " << a << ": " << exist_fp << endl;
			else cout << "no fixed point for " << a << endl;
		}
		++seq_counter;
		cout << endl;
	}
}	