#include <bits/stdc++.h>
using namespace std;
set<int> s;
int n;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int x; n--;) {
        cin >> x;
        s.insert(x);
    }
    for (auto x : s) {
        cout << x << " ";
    }
    return 0;
}