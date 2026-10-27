#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int c[26];
char s[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.getline(s, N);
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            c[s[i] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        cout << (char)('a' + i) << ":" << c[i];
        if (i % 5 == 4 || i == 25) {
            cout << "\n";
        } else {
            cout << " ";
        }
    }
    return 0;
}
