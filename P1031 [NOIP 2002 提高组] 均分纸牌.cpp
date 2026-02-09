#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, ans, a[110], num;
int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        num += a[i];
    }
    num /= n;
    for (ll i = 1; i < n; i++) {
        if (a[i] == num)
            continue;
        a[i + 1] += (a[i] - num);
        a[i] = num;
        ans++;
    }
    cout << ans;
    return 0;
}
