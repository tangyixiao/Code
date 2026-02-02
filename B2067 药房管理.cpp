#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n, cnt = 0;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (m >= x)
            m -= x;
        else
            cnt++;
    }
    cout << cnt;
    return 0;
}
