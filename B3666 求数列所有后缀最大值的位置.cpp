#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 1e6 + 5;
int n, a[N], ans;
struct node {
    int v, id;
};
stack<node> s;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (; !s.empty() && s.top().v <= a[i];) {
            ans ^= s.top().id;
            s.pop();
        }
        s.push({a[i], i});
        ans ^= s.top().id;
        cout << ans << "\n";
    }
    return 0;
}