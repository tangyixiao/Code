#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 33;
int t, sum, ans = -1, power[N];
signed main() {
    power[0] = 1;
    for (int i = 1; i < N; i++) {
        power[i] = power[i - 1] * 3;
    }
    cin >> t;
    for (int i = N; i >= 1; i--) {
        sum = (t + 2 - power[i - 1]) / power[i - 1];
        if (sum) {
            ans += sum;
            t -= sum * power[i - 1];
        }
    }
    cout << ans;
    return 0;
}