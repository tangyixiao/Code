#include <bits/stdc++.h>
using namespace std;

int n, i, f, cnt;
int a[10];

signed main() {
    for (i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a, a + 3);
    if (a[0] + a[1] <= a[2]) {
        cout << "no\n";
        return 0;
    }
    int s = a[0] * a[0] + a[1] * a[1];
    int t = a[2] * a[2];
    if (s == t) {
        cout << "zhijiao\n";
    } else if (s < t) {
        cout << "dunjiao\n";
    } else {
        cout << "ruijiao\n";
    }
    return 0;
}
