#include <bits/stdc++.h>
using namespace std;
int a[5], b[5], cnt;
signed main() {
    cin >> a[1] >> a[2] >> a[3] >> a[4];
    cin >> b[1] >> b[2] >> b[3] >> b[4];
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cnt += ((a[i] > a[j]) ^ (b[i] > b[j]));
        }
    }
    cout << cnt / 2;
    return 0;
}