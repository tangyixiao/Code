#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    while (m--) {
        int n;
        cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; ++i)
            cin >> h[i];

        vector<int> dp_len(n, 1);
        vector<int> dp_cnt(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (h[j] <= h[i]) {
                    if (dp_len[j] + 1 > dp_len[i]) {
                        dp_len[i] = dp_len[j] + 1;
                        dp_cnt[i] = dp_cnt[j];
                    } else if (dp_len[j] + 1 == dp_len[i]) {
                        dp_cnt[i] += dp_cnt[j];
                    }
                }
            }
        }

        int max_len = 0, total_cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (dp_len[i] > max_len) {
                max_len = dp_len[i];
                total_cnt = dp_cnt[i];
            } else if (dp_len[i] == max_len) {
                total_cnt += dp_cnt[i];
            }
        }

        cout << max_len << " " << total_cnt << "\n";
    }
    return 0;
}