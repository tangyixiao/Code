#include <bits/stdc++.h>
#define int long long
using namespace std;
string pr, su;
int ans;
signed main() {
    cin >> pr >> su;
    for (int i = 0; i < pr.size(); i++) {
        for (int j = 1; j < su.size(); j++) {
            if (su[j] == pr[i] && su[j - 1] == pr[i + 1]) {
                ans++;
            }
        }
    }
    ans = 1 << ans;
    cout << ans;
    return 0;
}