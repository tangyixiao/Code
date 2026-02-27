#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, Q = 4e5 + 5;
struct node {
    int d, w, ans;
    bool operator<(const node& rhs) const {
        if (d != rhs.d) {
            return d > rhs.d;
        }
        return ans < rhs.ans;
    }
} a[N];
int n, r, q;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r >> q;
    n <<= 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i].d;
        a[i].ans = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].w;
    }
    sort(a, a + n);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < n; j += 2) {
            if (a[j].w > a[j + 1].w) {
                a[j].d++;
            } else {
                a[j + 1].d++;
            }
        }
        stable_sort(a, a + n);
    }
    cout << a[q - 1].ans + 1;
    return 0;
}
