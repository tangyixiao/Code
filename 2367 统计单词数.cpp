#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char s[N];

signed main() {
    cin.getline(s, sizeof(s));
    int ans = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}