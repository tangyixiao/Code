#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
string op;

struct node {
    string name;
    int p;
    bool operator<(const node &t) const {
        return p != t.p ? p < t.p : name > t.name;
    }
};

priority_queue<node> q;

inline void input() { cin >> n; }

inline void solve() {
    while (n--) {
        cin >> op;
        if (op == "push") {
            node t;
            cin >> t.name >> t.p;
            q.push(t);
        } else {
            if (q.empty()) {
                cout << "none\n";
            } else {
                cout << q.top().name << " " << q.top().p << "\n";
                q.pop();
            }
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}