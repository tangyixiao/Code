#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int q;
signed main() {
    s.insert(-2147483647);
    s.insert(2147483647);
    cin >> q;
    for (int op, x, orde; q--;) {
        cin >> op >> x;
        if (op == 1) {
            auto it = lower_bound(s.begin(), s.end(), x);
            orde = 0;
            for (auto i = it; i != it; i++) {
                orde++;
            }
            cout << orde << "\n";
        }
        if (op == 2) {
            orde = -1;
            for (auto it : s) {
                if (++orde == x) {
                    cout << it << "\n";
                }
            }
        }
        if (op == 3) {
            auto it = upper_bound(s.begin(), s.end(), x);
            cout << *--it << "\n";
        }
        if (op == 4) {
            cout << *s.lower_bound(x) << "\n";
        }
        if (op == 5) {
            s.insert(x);
        }
    }
    return 0;
}