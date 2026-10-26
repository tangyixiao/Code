#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
long long v[N], x[N], tc[N], ts[N];
int id[N], n, i, X = 0;
long long ans = 0, cnt = 0, sum = 0;
int cmp(int a, int b) {
    return v[a] < v[b];
}
void add(int p) {
    for (int i = p; i <= X; i += i & -i) {
        tc[i]++, ts[i] += p;
    }
}
long long qc(int p) {
    long long s = 0;
    for (; p > 0; p -= p & -p) {
        s += tc[p];
    }
    return s;
}
long long qs(int p) {
    long long s = 0;
    for (; p > 0; p -= p & -p) {
        s += ts[p];
    }
    return s;
}
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> v[i] >> x[i];
        if (x[i] > X) {
            X = x[i];
        }
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    for (i = 1; i <= n; i++) {
        int k = id[i];
        long long cl = qc(x[k] - 1), sl = qs(x[k] - 1);
        long long d = (cl * x[k] - sl) + ((sum - sl) - (cnt - cl) * x[k]);
        ans += v[k] * d;
        add(x[k]);
        cnt++, sum += x[k];
    }
    cout << ans << "\n";
    return 0;
}
