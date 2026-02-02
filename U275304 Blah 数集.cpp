#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, i, a, x;
signed main() {
    while (cin >> a >> n) {
        set<int> s;
        i = 1;
        x = a;
        s.insert(x);
        for (auto it : s) {
            if (i == n) {
                cout << it << "\n";
                break;
            }
            x = it;
            s.insert(2 * x + 1);
            s.insert(3 * x + 1);
            i++;
        }
    }
    return 0;
}