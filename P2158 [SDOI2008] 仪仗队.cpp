#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 5;
int n, ans, phi[N];
bool v[N];
vector<int> prime;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n == 1) {
        cout << "0";
        return 0;
    }

    // 线性筛计算欧拉函数
    phi[1] = 1;
    for (int i = 2; i < n; i++) { // 只需计算到n-1
        if (!v[i]) {
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < prime.size() && i * prime[j] < n; j++) {
            v[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }

    // 计算欧拉函数前缀和
    for (int i = 1; i < n; i++) {
        ans += phi[i];
    }

    // 输出结果: 2 * sum + 1
    cout << (ans * 2 + 1) << endl;

    return 0;
}