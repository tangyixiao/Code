#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n;
char s[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.getline(s, N);
    n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            cout << " ";
            continue;
        }
        int j = i;
        for (; j < n && s[j] != ' '; j++) {
        }
        for (int k = j - 1; k >= i; k--) {
            cout << s[k];
        }
        i = j - 1;
    }
    cout << "\n";
    return 0;
}
