#include <bits/stdc++.h>
#define int long long
using namespace std;
string s, t;
int n, l;
signed main() {
    cin >> s >> n;
    l = s.size();
    for (int i; l < n;) {
        i = l;
        for (; n > i;) {
            i <<= 1;
        }
        i = i >> 1;
        n -= (i + 1);
        if (n == 0) {
            n = i;
        }
    }
    cout << s[n - 1];
    return 0;
}