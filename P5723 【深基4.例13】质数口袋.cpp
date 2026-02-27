#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, cnt;
bitset<N> num;
vector<int> prime;
inline void init() {
    for (int i = 2; i <= n; ++i) {
        if (!num[i])
            prime.push_back(i);
        for (int j = 0; j < prime.size(); ++j) {
            if (i * prime[j] >= n) {
                break;
            }
            num[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
signed main() {
    cin >> n;
    init();
    for (auto it : prime) {
        if (n - it >= 0) {
            cout << it << "\n";
            n -= it;
            cnt++;
        } else {
            break;
        }
    }
    cout << cnt << "\n";
    return 0;
}