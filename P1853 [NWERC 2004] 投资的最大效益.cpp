#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long s;
    int n, d;
    cin >> s >> n >> d;

    vector<pair<int, int>> bonds(d);
    for (int i = 0; i < d; ++i) {
        int a, b;
        cin >> a >> b;
        bonds[i] = {a / 1000, b};
    }

    for (int year = 0; year < n; ++year) {
        int cap = s / 1000;
        vector<long long> dp(cap + 1, 0);

        for (auto &[w, v] : bonds) {
            if (w > cap)
                continue;
            for (int j = w; j <= cap; ++j) {
                if (dp[j - w] + v > dp[j])
                    dp[j] = dp[j - w] + v;
            }
        }

        long long interest = dp[cap];
        s += interest;
    }

    cout << s << endl;
    return 0;
}