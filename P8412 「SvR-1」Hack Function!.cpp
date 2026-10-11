#include <bits/stdc++.h>
using namespace std;

namespace TANGYIXIAO {
inline long long mod_pow(long long a, int e, int mod) {
    long long r = 1 % mod;
    for (; e; e >>= 1, a = a * a % mod) {
        if (e & 1) {
            r = r * a % mod;
        }
    }
    return r;
}

inline int euler_phi(int x) {
    int r = x;
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            r = r / d * (d - 1);
            for (; x % d == 0; x /= d) {
            }
        }
    }
    if (x > 1) {
        r = r / x * (x - 1);
    }
    return r;
}

inline bool find_cycle_segment(const vector<int> &v, long long target, int &start, int &len) {
    if (target <= 0) {
        return false;
    }
    int n = (int)v.size(), right = 0;
    long long sum = 0;
    for (int left = 0; left < n; left++) {
        for (; right < left + n && sum < target; right++) {
            sum += v[right % n];
        }
        if (sum == target) {
            start = left, len = right - left;
            return true;
        }
        if (right > left) {
            sum -= v[left];
        }
    }
    return false;
}

inline void print_answer(long long l, long long r) {
    cout << l << ' ' << r << '\n';
    return;
}

inline void solve(int Task_Id) {
    int k;
    long long p;
    cin >> k >> p;
    int q = k - 1, phi = euler_phi(q), period_len = q * phi;
    vector<int> pre(q), cyc(period_len);
    for (int i = 1; i < q; i++) {
        int x = (int)mod_pow(i, i, q);
        pre[i] = x ? x : q;
    }
    for (int x = 0; x < q; x++) {
        if (x == 0) {
            for (int t = 0; t < phi; t++) {
                cyc[t * q] = q;
            }
            continue;
        }
        long long value = mod_pow(x, q + x, q);
        long long ratio = mod_pow(x, q, q);
        for (int t = 0; t < phi; t++) {
            int at = x + t * q;
            cyc[at] = value ? (int)value : q;
            value = value * ratio % q;
        }
    }
    long long cycle_sum = 0;
    for (int x : cyc) {
        cycle_sum += x;
    }

    for (int l = 1; l < q; l++) {
        long long sum = 0;
        for (int r = l; r < q; r++) {
            sum += pre[r];
            if (sum == p) {
                print_answer(l, r);
                return;
            }
            if (sum > p) {
                break;
            }
        }
    }

    long long full = p / cycle_sum, rem = p % cycle_sum;
    if (rem == 0 && full > 0) {
        print_answer(q, q + full * period_len - 1);
        return;
    }
    int start, len;
    if (find_cycle_segment(cyc, rem, start, len)) {
        long long l = q + start;
        print_answer(l, l + full * period_len + len - 1);
        return;
    }

    vector<long long> prefix(period_len + 1);
    for (int i = 0; i < period_len; i++) {
        prefix[i + 1] = prefix[i] + cyc[i];
    }
    vector<long long> suffix(q + 1);
    for (int i = q - 1; i >= 1; i--) {
        suffix[i] = suffix[i + 1] + pre[i];
    }
    for (int l = 1; l < q; l++) {
        if (p < suffix[l]) {
            continue;
        }
        long long target = p - suffix[l];
        long long cycles = target / cycle_sum, tail = target % cycle_sum;
        auto it = lower_bound(prefix.begin(), prefix.begin() + period_len, tail);
        if (it == prefix.begin() + period_len || *it != tail) {
            continue;
        }
        long long tail_len = it - prefix.begin();
        long long periodic_len = cycles * period_len + tail_len;
        if (periodic_len > 0) {
            print_answer(l, q - 1 + periodic_len);
            return;
        }
    }

    print_answer(-1, -1);
    return;
}
} // namespace TANGYIXIAO

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int Task_Id = 1; Task_Id <= T; Task_Id++) {
        TANGYIXIAO::solve(Task_Id);
    }
    return 0;
}
