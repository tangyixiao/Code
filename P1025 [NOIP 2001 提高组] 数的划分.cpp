//  Author: Tangyixiao
//  Time: 2026-10-04 23:09:33
//  Problem: P1025 [NOIP 2001 提高组] 数的划分
//  Contest: Luogu
//  URL: https://www.luogu.com.cn/problem/P1025
//  Memory Limit: 125 MB
//  Time Limit: 1000 ms
//  Interactive: false
//  Test Type: single
//
//  Algorithm:
//  Complexity: O()
//  Note:
//
//  Powered by Visual Studio Code + CPH (Competitive Programming Helper)

#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
int n, k, f[201][7];
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        f[i][1] = 1, f[i][0] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int x = 2; x <= k; x++) {
            if (i > x) {
                f[i][x] = f[i - 1][x - 1] + f[i - x][x];
            } else {
                f[i][x] = f[i - 1][x - 1];
            }
        }
    }
    cout << f[n][k];
    return 0;
}
