#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x % 9 == 0 && x % 8)
            cnt++;
    }
    cout << cnt;
    return 0;
}