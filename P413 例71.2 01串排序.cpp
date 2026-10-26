#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, i;
string s[N];
int ones[N];
bool cmp(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    int ca = 0, cb = 0;
    for (size_t k = 0; k < a.size(); k++) {
        ca += a[k] - '0';
    }
    for (size_t k = 0; k < b.size(); k++) {
        cb += b[k] - '0';
    }
    if (ca != cb) {
        return ca < cb;
    }
    return a < b;
}
signed main() {
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n, cmp);
    for (i = 0; i < n; i++) {
        cout << s[i] << "\n";
    }
    return 0;
}
