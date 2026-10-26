#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;
int v[N], d[N];

signed main() {
    int n, A, B;
    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        d[i] = -1;
    }
    queue<int> q;
    d[A] = 0;
    q.push(A);
    for (; !q.empty();) {
        int x = q.front();
        q.pop();
        int nx = x + v[x];
        if (nx <= n && d[nx] == -1) {
            d[nx] = d[x] + 1;
            q.push(nx);
        }
        nx = x - v[x];
        if (nx >= 1 && d[nx] == -1) {
            d[nx] = d[x] + 1;
            q.push(nx);
        }
    }
    cout << d[B] << "\n";
    return 0;
}
