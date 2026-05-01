#include <bits/stdc++.h>
using namespace std;
struct Node {
    int cnt;
    unordered_map<char, Node *> ch;
    Node()
        : cnt(0) {};

    void dfs() {
        for (auto [x, y] : ch) {
            y->dfs();
            cnt += y->cnt;
        }
    }
};
Node *rot;
string s;
int T, n, q;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n >> q;
        rot = new Node();
        for (int i = 1; i <= n; ++i) {
            cin >> s;
            auto u = rot;
            for (auto c : s)
                u = (u->ch[c] ? u->ch[c] : u->ch[c] = new Node);
            ++u->cnt;
        }
        rot->dfs();
        for (int i = 1; i <= q; ++i) {
            cin >> s;
            bool flag = true;
            auto u = rot;
            for (auto c : s)
                if (u->ch[c]) {
                    u = u->ch[c];
                } else {
                    flag = false;
                    break;
                }
            cout << (flag ? u->cnt : 0) << '\n';
        }
    }
    return 0;
}
