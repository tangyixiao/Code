#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 32000;

struct Item {
    int v;
    int p;
    int q;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Item> items(m + 1);

    vector<vector<int>> attach(m + 1);

    for (int i = 1; i <= m; ++i) {
        cin >> items[i].v >> items[i].p >> items[i].q;
        if (items[i].q != 0) {
            attach[items[i].q].push_back(i);
        }
    }

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
        if (items[i].q != 0)
            continue;

        int v_main = items[i].v;
        int p_main = items[i].p;
        int w_main = v_main * p_main;

        int cnt = attach[i].size();
        int v1 = 0, w1 = 0, v2 = 0, w2 = 0;
        if (cnt >= 1) {
            int id1 = attach[i][0];
            v1 = items[id1].v;
            w1 = v1 * items[id1].p;
        }
        if (cnt >= 2) {
            int id2 = attach[i][1];
            v2 = items[id2].v;
            w2 = v2 * items[id2].p;
        }

        for (int j = n; j >= 0; --j) {

            if (j >= v_main)
                dp[j] = max(dp[j], dp[j - v_main] + w_main);

            if (cnt >= 1 && j >= v_main + v1)
                dp[j] = max(dp[j], dp[j - v_main - v1] + w_main + w1);

            if (cnt >= 2 && j >= v_main + v2)
                dp[j] = max(dp[j], dp[j - v_main - v2] + w_main + w2);

            if (cnt >= 2 && j >= v_main + v1 + v2)
                dp[j] = max(dp[j], dp[j - v_main - v1 - v2] + w_main + w1 + w2);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}