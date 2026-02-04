#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, a[N], b[N], cnt;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cnt = 1;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        stack<int> s;
        for (int i = 1; i <= n; i++) {   
            s.push(a[i]);
            for (; s.top() == b[cnt] && !s.empty();) {
                s.pop();
                cnt++;
                if (s.empty()) {
                    break;
                }
            }
        }
        if (s.empty()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}