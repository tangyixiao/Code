#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, x, ans;
char s[15], c;

inline void input() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        x = x * 2 + (s[i] - '0');
    }
    cout << x << "\n";
    return;
}

signed main() {
    input();
    return 0;
}