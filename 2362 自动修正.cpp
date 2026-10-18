#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char s[N];

signed main() {
    cin >> s;
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
    }
    cout << s << "\n";
    return 0;
}