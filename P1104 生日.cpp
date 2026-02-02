#include <bits/stdc++.h>
using namespace std;
struct sr {
    string name;
    int n, y, r, xh;
} a[100005];
bool cmp(sr a, sr b) {
    if (a.n != b.n) {
        return a.n < b.n;
    }
    if (a.y != b.y) {
        return a.y < b.y;
    }
    if (a.r != b.r) {
        return a.r < b.r;
    }
    return a.xh > b.xh;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    for (int i = 1; i <= x; i++) {
        cin >> a[i].name >> a[i].n >> a[i].y >> a[i].r;
        a[i].xh = i;
    }
    sort(a + 1, a + 1 + x, cmp);
    for (int i = 1; i <= x; i++) {
        cout << a[i].name << "\n";
    }
    return 0;
}
