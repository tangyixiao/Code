#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int v[N], ix[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, top = 0;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        for (; top > 0 && v[top] <= x;) {
            ans ^= ix[top];
            top--;
        }
        top++;
        v[top] = x;
        ix[top] = i;
        ans ^= i;
        cout << ans << "\n";
    }
    return 0;
}
