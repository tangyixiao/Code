#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, la;
set<int> s;
namespace Tangyixiao {
    inline void solve() {
        cin >> la;
        s.insert(0);
        for (int i = 2, x; i <= n; ++i) {
            cin >> x;
            s.insert(x);
            s.insert((x | la) ^ la);
            s.insert((x | la) ^ x);
            s.insert(x | la);
            s.insert(x & la);
            s.insert(x ^ la);
            s.insert(la);
            la = x;
        }
        cout << s.size();
        return;
    }
    inline void init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cin >> n;
        return;
    }
} // namespace Tangyixiao
main() {
    Tangyixiao::init();
    Tangyixiao::solve();
    return 0;
}
