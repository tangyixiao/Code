#include <bits/stdc++.h>
using namespace std;
int n, k, a;
set<int> s;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        s.insert(a);
    }
    int i = 1;
    for (auto it : s) {
        if (i > k) {
            break;
        }
        if (i == k) {
            cout << it << endl;
            exit(0);
        }
        i++;
    }
    cout << "NO RESULT";
    return 0;
}