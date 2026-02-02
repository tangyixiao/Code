#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
long long T, n, k;
int main() {
    for (cin >> T; T; T--) {
        cin >> n >> k;
        if (k != 0)
            cout << n / k - n / (k + 1) << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}