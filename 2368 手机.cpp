#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char s[] = "12312312312312312341231234", t[N];

signed main() {
    cin.getline(t, sizeof(t));
    int ans = 0;
    for (int i = 0; t[i]; i++) {
        ans += t[i] == ' ' ? 1 : s[t[i] - 'a'] - '0';
    }
    cout << ans << "\n";
    return 0;
}