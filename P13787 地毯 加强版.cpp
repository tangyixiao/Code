#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> diff((n + 2) * (n + 2), 0);
    auto idx = [&](int x, int y) {
        return x * (n + 2) + y;
    };

    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        diff[idx(x1, y1)] += 1;
        diff[idx(x1, y2 + 1)] -= 1;
        diff[idx(x2 + 1, y1)] -= 1;
        diff[idx(x2 + 1, y2 + 1)] += 1;
    }

    unsigned long long ans = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {

            int cur = diff[idx(i, j)] + diff[idx(i - 1, j)] + diff[idx(i, j - 1)] - diff[idx(i - 1, j - 1)];
            diff[idx(i, j)] = cur;
            ans += static_cast<unsigned long long>((i + j) ^ cur);
        }
    }

    cout << ans << '\n';
    return 0;
}