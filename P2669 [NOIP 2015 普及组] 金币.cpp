#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
int k, n;
signed main() {
    cin >> k;
    int i, coins = 0;
    for (i = 1; k > i; i++) {
        coins += i * i;
        k -= i;  
    }
    coins += k * i;
    cout << coins;
    return 0;
}