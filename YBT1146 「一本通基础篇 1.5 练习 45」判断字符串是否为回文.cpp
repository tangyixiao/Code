#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char s[N];

signed main() {
    cin >> s;
    int n = strlen(s);
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            cout << "no\n";
            return 0;
        }
    }
    cout << "yes\n";
    return 0;
}
