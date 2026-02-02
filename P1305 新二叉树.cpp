#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;
const int N = 27;
int n;
string s;
vector<int> v[N];
inline void dfs(int u) {
    cout << (char)(u + 'a');
    for (auto it : v[u]) {
        dfs(it);
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> s;
    if (s[1] != '*') {
        v[s[0] - 'a'].push_back(s[1] - 'a');
    }
    if (s[2] != '*') {
        v[s[0] - 'a'].push_back(s[2] - 'a');
    }
    int rt = s[0] - 'a';
    for (int i = 2; i <= n; i++) {
        cin >> s;
        if (s[1] != '*') {
            v[s[0] - 'a'].push_back(s[1] - 'a');
        }
        if (s[2] != '*') {
            v[s[0] - 'a'].push_back(s[2] - 'a');
        }
    }
    dfs(rt);

#ifdef DEBUG
    for (int i = 1; i <= n; i++) {
        debug(i);
        for (auto it : v[i]) {
            debug(it);
            cerr << " ";
        }
        cerr << "\n";
    }
#endif
    return 0;
}
