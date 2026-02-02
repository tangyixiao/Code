#include <bits/stdc++.h>
using namespace std;
int n, ans[14] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cout << ans[n];
    return 0;
}