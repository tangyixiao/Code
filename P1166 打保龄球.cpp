#pragma G++ optimize("O3", "Ofast", "unroll-loops", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 15;
struct po {
    char fi, sc;
} c[N * N];
int lun = 10, ju = 10, sum[N], num;
bool flag;
bool isx(char c) { return c == '/'; }
bool ist(char c) { return c >= '0'; }
inline int de(char c) {
    if (c == '/') {
        return 10;
    }
    return c - '0';
}
inline void solve();
signed main() {
    for (int i = 1; i <= lun; i++) {
        cin >> c[i].fi;
        if (flag && isx(c[i].fi)) {
            lun++;
        }
        if (i == 10 && isx(c[i].fi)) {
            lun++;
            flag = true;
        }
        if (c[i].fi != '/') {
            cin >> c[i].sc;
            if (i == 10 && isx(c[i].sc)) {
                lun++;
            }
        }
    }
    solve();
    cout << '\n';
    for (int i = 1; i <= ju; i++) {
        cout << sum[i] << " ";
    }
    return 0;
}
inline void solve() {
    for (int i = 1; i <= 10; i++) {
        if (isx(c[i].fi)) {
            if (isx(c[i + 1].fi)) {
                if (isx(c[i + 2].fi)) {
                    num = 30;
                } else {
                    if (ist(c[i + 2].fi)) {
                        num = 20 + de(c[i + 2].fi);
                    } else {
                        ju = i - 1;
                        break;
                    }
                }
            } else {
                if (isx(c[i + 1].sc)) {
                    num = 20;
                } else {
                    if (ist(c[i + 1].fi) && ist(c[i + 1].sc)) {
                        num = 10 + de(c[i + 1].fi) + de(c[i + 1].sc);
                    } else {
                        ju = i - 1;
                        break;
                    }
                }
            }
        } else {
            if (isx(c[i].sc)) {
                if (isx(c[i + 1].fi)) {
                    num = 20;
                } else {
                    if (ist(c[i + 1].fi))
                        num = 10 + de(c[i + 1].fi);
                    else {
                        ju = i - 1;
                        break;
                    }
                }
            } else {
                if (ist(c[i].sc))
                    num = de(c[i].fi) + de(c[i].sc);
                else {
                    ju = i - 1;
                    break;
                }
            }
        }
        sum[i] = sum[i - 1] + num;
        cout << num << " ";
    }
    return;
}
