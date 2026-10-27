#include <bits/stdc++.h>
using namespace std;

string s;
long long ans;

signed main() {
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        ans = ans * 2 + (s[i] - '0');
    }
    cout << ans << "\n";
    return 0;
}
