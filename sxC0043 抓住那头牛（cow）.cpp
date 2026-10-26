#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int d[N];

signed main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < N; i++) {
        d[i] = -1;
    }
    queue<int> q;
    d[n] = 0;
    q.push(n);
    for (; !q.empty();) {
        int x = q.front();
        q.pop();
        if (x == k) {
            break;
        }
        int nx = x - 1;
        if (nx >= 0 && d[nx] == -1) {
            d[nx] = d[x] + 1;
            q.push(nx);
        }
        nx = x + 1;
        if (nx < N && d[nx] == -1) {
            d[nx] = d[x] + 1;
            q.push(nx);
        }
        nx = x * 2;
        if (nx < N && d[nx] == -1) {
            d[nx] = d[x] + 1;
            q.push(nx);
        }
    }
    cout << d[k] << "\n";
    return 0;
}
