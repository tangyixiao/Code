#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char s[N];

signed main() {
    cin >> s;
    int n = 0;
    while (s[n]) {
        n++;
    }
    if (n >= 2 && s[n - 1] == 'r' && s[n - 2] == 'e') {
        n -= 2;
    } else if (n >= 2 && s[n - 1] == 'y' && s[n - 2] == 'l') {
        n -= 2;
    }
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << "\n";
    return 0;
}