#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> p(N + 1);
    vector<int> pos(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    vector<int> pref(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        pref[i] = pref[i - 1] + (p[i] == i ? 1 : 0);
    }

    int maxC = 2 * N;
    vector<int> cnt(maxC + 2, 0);
    for (int i = 1; i <= N; ++i) {
        int c = i + pos[i];
        cnt[c]++;
    }

    int best_gain = 0;
    int best_l = 1, best_r = 1;

    for (int c = 2; c <= maxC; ++c) {
        if (cnt[c] == 0)
            continue;
        int L = max(1, c - N);
        int R = min(N, c - 1);
        int fixed_in = pref[R] - pref[L - 1];
        int gain = cnt[c] - fixed_in;
        if (gain > best_gain) {
            best_gain = gain;
            best_l = L;
            best_r = R;
        }
    }

    cout << p[best_l] << ' ' << p[best_r] << '\n';
    return 0;
}