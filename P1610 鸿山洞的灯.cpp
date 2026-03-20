#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, dist;
    cin >> n >> dist;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    vector<int> prev(n), next(n);
    for (int i = 0; i < n; ++i) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    next[n - 1] = -1;
    prev[0] = -1;

    int ans = 0;
    int i = 1;
    while (i != -1) {
        int left = prev[i];
        int right = next[i];

        if (left != -1 && right != -1 && p[right] - p[left] <= dist) {
            ++ans;

            next[left] = right;
            prev[right] = left;

            i = left;
        } else {
            i = next[i];
        }
    }

    cout << ans << '\n';
    return 0;
}