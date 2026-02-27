#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;
int n, a[N];
long long ans = 1;
bitset<N> num;
vector<int> prime;
inline void init() {
    for (int i = 2; i <= N - 1; ++i) {
        if (!num[i])
            prime.push_back(i);
        for (int j = 0; j < prime.size(); ++j) {
            if (i * prime[j] >= N - 1) {
                break;
            }
            num[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    return;
}
signed main() {
    init();
    cin >> n;
    for (int i = 1, id; i <= n; i++) {
        id = i;
        for (auto it : prime) {
            if (id <= 1) {
                break;
            }
            while (id % it == 0) {
                id /= it;
                a[it]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans *= (2 * a[i] + 1);
        ans %= mod;
    }
    cout << ans;
    return 0;
}