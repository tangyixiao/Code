#include <bits/stdc++.h>
using namespace std;

char s[305], q[305];
int b, i, len, k;

signed main() {
    cin >> s >> b;
    len = strlen(s);
    long long rem = 0;
    k = 0;
    for (i = 0; i < len; i++) {
        rem = rem * 10 + (s[i] - '0');
        q[k] = '0' + rem / b;
        k++;
        rem %= b;
    }
    int st = 0;
    while (st < k - 1 && q[st] == '0') {
        st++;
    }
    for (i = st; i < k; i++) {
        cout << q[i];
    }
    if (rem == 0) {
        cout << "\n";
        return 0;
    }
    cout << ".";
    for (i = 1; i <= 100; i++) {
        rem = rem * 10;
        cout << (char)('0' + rem / b);
        rem %= b;
        if (rem == 0) {
            break;
        }
    }
    cout << "\n";
    return 0;
}
