#include <bits/stdc++.h>
using namespace std;
int a[20000005], n, num, ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1])
            num++;
    }
    ans = a[n] * 10 + num * 5 + n;
    cout << ans;

    return 0;
}
