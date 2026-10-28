#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n;
string s[N];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    sort(s + 1, s + n + 1, [](const string &a, const string &b) { return a + b > b + a; });
    for (int i = 1; i <= n; i++) {
        cout << s[i];
    }
    cout << "\n";
    return 0;
}
