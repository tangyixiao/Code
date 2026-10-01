//  Author: Tangyixiao
//  Time: 2026-10-01 18:56:09
//  Problem: P10468 兔子与兔子
//  Contest: Luogu
//  URL: https://www.luogu.com.cn/problem/P10468
//  Memory Limit: 512 MB
//  Time Limit: 1000 ms
//  Interactive: false
//  Test Type: single
//
//  Algorithm:
//  Complexity: O()
//  Note:
//
//  Powered by Visual Studio Code + CPH (Competitive Programming Helper)

#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 1e6 + 5, base = 13331;
int a[N], power[N];
int get_hash(int l, int r) {
    return a[r] - a[l] * power[r - l];
}
string x;
int n, m;
signed main() {
    cin >> x >> n;
    m = x.size(), x = " " + x, power[0] = 1;
    for (int i = 1; i <= m; i++) {
        a[i] = a[i - 1] * base + x[i], power[i] = power[i - 1] * base;
    }
    for (int i = 1, l1, r1, l2, r2; i <= n; i++) {
        cin >> l1 >> r1 >> l2 >> r2;
        if (get_hash(l1, r1) == get_hash(l2, r2)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
