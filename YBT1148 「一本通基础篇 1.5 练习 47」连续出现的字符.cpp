#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;

char s[N];
int k;

signed main() {
    cin >> k >> s;
    for (int i = 0, c = 1; s[i]; i++) {
        c = s[i] == s[i - 1] || i == 0 ? c + 1 : 1;
        if (c >= k) {
            cout << s[i] << "\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
