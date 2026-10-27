#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
map<string, int> mp;
char s[N], w[64];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.getline(s, N);
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
        if (!(s[i] >= 'a' && s[i] <= 'z')) {
            s[i] = ' ';
        }
    }
    int best = 0;
    string bs;
    for (int i = 0; s[i];) {
        if (s[i] == ' ') {
            i++;
            continue;
        }
        int k = 0;
        for (; s[i] && s[i] != ' '; i++) {
            w[k++] = s[i];
        }
        w[k] = 0;
        int c = ++mp[w];
        if (c > best || (c == best && string(w) < bs)) {
            best = c;
            bs = w;
        }
    }
    cout << bs << " " << best << "\n";
    return 0;
}
