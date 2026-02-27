#include <bits/stdc++.h>
using namespace std;
const int N = 114;
int n, d[N], a[N], p[N], maxn;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        d[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                d[i] = max(d[j] + 1, d[i]);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        p[i] = 1;
        for (int j = n; j > i; j--) {
            if (a[i] > a[j]) {
                p[i] = max(p[j] + 1, p[i]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        maxn = max(d[i] + p[i] - 1, maxn);
    }
    cout << n - maxn;
    return 0;
}