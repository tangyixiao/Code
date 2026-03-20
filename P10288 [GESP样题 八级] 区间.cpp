#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        unordered_map<int, vector<int>> pos;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            pos[x].push_back(i);
        }

        int q;
        cin >> q;
        while (q--) {
            int l, r, x;
            cin >> l >> r >> x;
            auto it = pos.find(x);
            if (it == pos.end()) {
                cout << "0\n";
                continue;
            }
            const vector<int> &v = it->second;

            int cnt = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
            cout << cnt << '\n';
        }
    }
    return 0;
}