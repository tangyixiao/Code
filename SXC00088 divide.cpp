#include <bits/stdc++.h>
using namespace std;

int g;

inline int per(string s, int L) {
    int n = s.size();
    for (int i = L; i < n; i += L) {
        if (s.compare(i, L, s, 0, L) != 0) {
            return 0;
        }
    }
    return 1;
}

signed main() {
    string a, b;
    cin >> a >> b;
    int la = a.size(), lb = b.size(), c = 0;
    for (int L = 1; L <= la && L <= lb; L++) {
        if (la % L || lb % L) {
            continue;
        }
        if (a.compare(0, L, b, 0, L) != 0) {
            continue;
        }
        if (per(a, L) && per(b, L)) {
            c++;
        }
    }
    cout << c << "\n";
    return 0;
}
