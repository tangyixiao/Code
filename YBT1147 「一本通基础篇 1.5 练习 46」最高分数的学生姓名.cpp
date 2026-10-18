#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, mx = -1;
char s[N][25], t[N];

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x >> t;
        if (x > mx) {
            mx = x;
            strcpy(s[0], t);
        }
    }
    cout << s[0] << "\n";
    return 0;
}
