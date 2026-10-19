#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
string nm[N];
map<string, int> id;
int fa[N], n, fst;

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline int get(const string &s) {
    if (!id.count(s)) {
        id[s] = ++n;
        fa[n] = n, nm[n] = s;
    }
    return id[s];
}

inline void input() {}

inline void solve() {
    string s;
    while (getline(cin, s)) {
        if (!s.size()) {
            continue;
        }
        if (s[s.size() - 1] == '\r') {
            s.erase(s.size() - 1);
        }
        char c = s[0];
        if (c == '$') {
            break;
        }
        int u = get(s.substr(1));
        if (c == '#') {
            fst = u;
        } else if (c == '+') {
            fa[u] = find(fst);
        } else {
            cout << s.substr(1) << " " << nm[find(u)] << "\n";
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}