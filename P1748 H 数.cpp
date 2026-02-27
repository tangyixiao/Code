#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5;
int a[N], n, cnt2, cnt3, cnt5, cnt7;
signed main() {
    a[1] = 1;
    cnt2 = cnt3 = cnt5 = cnt7 = 1;
    for (int i = 2; i <= N - 5; i++) {
        a[i] = min(min(a[cnt2] * 2, a[cnt3] * 3), min(a[cnt5] * 5, a[cnt7] * 7));
        cnt2 += (a[i] == (a[cnt2] * 2)), cnt3 += (a[i] == (a[cnt3] * 3));
        cnt5 += (a[i] == (a[cnt5] * 5)), cnt7 += (a[i] == (a[cnt7] * 7));
    }
    for (; cin >> n;) {
        cout << a[n] << "\n";
    }
    return 0;
}