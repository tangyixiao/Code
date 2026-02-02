#include<bits/stdc++.h>
using namespace std;
bool b[101], c;
int main() {
	string s;
	int ans = 0, l;
	cin >> l >> s;
	s = ' ' + s;
	for (int i = 1; i < l; i++) {
		if (s[i] == 'V' and s[i + 1] == 'K') {
			b[i] = true, b[i + 1] = true;
			ans++;
			i++;
		} else if ((s[i] == 'V' and s[i + 1] == 'V' and s[i + 2]!='K') or ((i == 1 or s[i - 1] != 'V') and (s[i] == 'K' and s[i + 1] == 'K'))) {
			c = true;
		}
	}
	if (c) cout << ans + 1;
	else cout << ans;
	return 0;
}
