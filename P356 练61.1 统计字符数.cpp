#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char s[N];
int f[N];

signed main() {
    cin >> s;
    for (int i = 0; s[i]; i++) {
        f[s[i] - 'a']++;
    }
    int k = 0;
    for (int i = 1; i < 26; i++) {
        if (f[i] > f[k]) {
            k = i;
        }
    }
    cout << char(k + 'a') << " " << f[k] << "\n";
    return 0;
}