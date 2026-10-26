#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;
int c[N];

signed main() {
    string s1, s2;
    freopen("ybtbas.in", "r", stdin);
    freopen("ybtbas.out", "w", stdout);
    cin >> s1 >> s2;
    int la = s1.size(), lb = s2.size(), l = max(la, lb);
    for (int i = 0; i < l; i++) {
        int x = (i < la) ? s1[la - 1 - i] - '0' : 0;
        int y = (i < lb) ? s2[lb - 1 - i] - '0' : 0;
        c[i] += x + y;
        if (c[i] >= 10) {
            c[i] -= 10;
            c[i + 1]++;
        }
    }
    if (c[l]) {
        l++;
    }
    for (; l > 1 && c[l - 1] == 0;) {
        l--;
    }
    for (int i = l - 1; i >= 0; i--) {
        cout << c[i];
    }
    cout << "\n";
    return 0;
}
