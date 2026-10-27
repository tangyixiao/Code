#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, best = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n;) {
        int j = i;
        for (; j <= n && a[j] == a[i];) {
            j++;
        }
        int lenL = j - i;
        if (j <= n) {
            int k = j;
            for (; k <= n && a[k] != a[i];) {
                k++;
            }
            int lenR = k - j;
            int t = lenL < lenR ? lenL : lenR;
            if (2 * t > best) {
                best = 2 * t;
            }
        }
        i = j;
    }
    cout << best << "\n";
    return 0;
}
