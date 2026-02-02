#include <bits/stdc++.h>
using namespace std;
int ans;
string s;
signed main() {
    while (cin >> s) {
        ans += s.size();
    }
    cout << ans;
    return 0;
}