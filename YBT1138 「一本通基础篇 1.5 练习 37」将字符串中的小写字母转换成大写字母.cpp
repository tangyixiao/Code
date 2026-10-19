#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char s[N];

signed main() {
    cin.getline(s, N);
    int n = strlen(s);
    if (n && s[n - 1] == '\r') {
        s[--n] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
    }
    cout << s << "\n";
    return 0;
}
