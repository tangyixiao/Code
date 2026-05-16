#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll a;
        int n, p, q;
        cin >> a >> n >> p >> q;
        if (p > q)
            swap(p, q);
        string s = to_string(a);
        int L = s.size();
        char mn = '0' + p, mx = '0' + q;

        string r(L, '0');
        int i = 0, g = 0;
        while (i < L) {
            if (g) {
                r[i] = mn;
                i++;
                continue;
            }
            int c = s[i] - '0';
            int d = -1;
            if (c <= p)
                d = p;
            else if (c <= q)
                d = q;
            if (d != -1) {
                r[i] = '0' + d;
                if (d > c)
                    g = 1;
                i++;
            } else {
                int j = i - 1;
                while (j >= 0 && r[j] != mn)
                    j--;
                if (j == -1) {
                    if (p == 0)
                        r = mx + string(L, mn);
                    else
                        r = mn + string(L, mn);
                    break;
                } else {
                    r[j] = mx;
                    g = 1;
                    i = j + 1;
                }
            }
        }
        ll ge = stoll(r);

        string R(L, '0');
        int I = 0, lt = 0;
        bool ok = true;
        ll le = 0;
        while (I < L) {
            if (lt) {
                R[I] = mx;
                I++;
                continue;
            }
            int c = s[I] - '0';
            int d = -1;
            if (c >= q)
                d = q;
            else if (c >= p)
                d = p;
            if (d != -1) {
                R[I] = '0' + d;
                if (d < c)
                    lt = 1;
                I++;
            } else {
                int J = I - 1;
                while (J >= 0 && R[J] != mx)
                    J--;
                if (J == -1) {
                    if (L - 1 == 0) {
                        if (p == 0)
                            R = "0";
                        else
                            ok = false;
                    } else {
                        R = string(L - 1, mx);
                    }
                    break;
                } else {
                    R[J] = mn;
                    lt = 1;
                    I = J + 1;
                }
            }
        }
        if (ok)
            le = stoll(R);

        ll ans = llabs(a - ge);
        if (ok) {
            ll d = llabs(a - le);
            if (d < ans)
                ans = d;
        }
        cout << ans << '\n';
    }
    return 0;
}