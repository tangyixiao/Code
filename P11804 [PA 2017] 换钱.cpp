#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int max_a = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > max_a)
            max_a = a[i];
    }

    const int SIZE = max_a + 100;
    vector<long long> cnt(SIZE, 0);

    for (int i = 0; i < n; ++i) {
        cnt[a[i]]++;
    }

    for (int i = 0; i < SIZE - 1; ++i) {
        cnt[i + 1] += cnt[i] / 2;
        cnt[i] %= 2;
    }

    int ans = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (cnt[i] == 1)
            ans = i;
    }

    cout << ans << '\n';
    return 0;
}