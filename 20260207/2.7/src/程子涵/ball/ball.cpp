#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[100005];
signed main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char c;
	int n = 0;
	for (int i = 1; cin >> c && c != 'E'; i++) {
		a[i] = c;
		n = i;
	}
	int w = 0, l = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 'W') {
			w++;
		}
		if (a[i] == 'L') {
			l++;
		}
		if ((w >= 11 || l >= 11) && (w + 2 <= l || l + 2 <= w)) {
			cout << w << ":" << l << endl;
			w = 0;
			l = 0;
		}
	}
	cout << w << ":" << l << endl;
	cout << endl;
	w = 0;
	l = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 'W') {
			w++;
		}
		if (a[i] == 'L') {
			l++;
		}
		if ((w >= 21 || l >= 21) && (w + 2 <= l || l + 2 <= w)) {
			cout << w << ":" << l << endl;
			w = 0;
			l = 0;
		}
	}
	cout << w << ":" << l;
	return 0;
}
