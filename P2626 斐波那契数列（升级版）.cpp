#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1 << 31, N = 51;
int n, f[N];
queue<int> q;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    cout << f[n] << "=";
    for (int i = 2; i * i <= f[n]; i++) {
        for (; !(f[n] % i); f[n] /= i) {
            q.push(i);
        }
    }
    for (; !q.empty(); q.pop()) {
        cout << q.front();
        if (q.size() > 1) {
            cout << "*";
        }
    }
    if (f[n] > 1) {
        cout << f[n];
    }
    return 0;
}