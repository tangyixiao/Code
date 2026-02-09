#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct Sec {
    int l, r;
    bool operator<(const Sec &b) const {
        if (r != b.r) {
            return r < b.r;
        }
        return l > b.l;
    }
} s[N];
int n, ct = 0, lastR = -1;
int main() {
    for (; cin >> s[n].l >> s[n].r;) {
        n++;
    }
    sort(s, s + n);
    for (int i = 0; i < n; ++i) {
        if (s[i].l > lastR) {
            ct++;
            lastR = s[i].r;
        }
    }
    cout << ct;
    return 0;
}
