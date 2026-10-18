#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;

char s[N][N];
int n, p;

inline double calc(int &i) {
    if (s[i][0] == '+' || s[i][0] == '-' || s[i][0] == '*' || s[i][0] == '/') {
        char o = s[i++][0];
        double b = calc(i), c = calc(i);
        if (o == '+') {
            return b + c;
        }
        if (o == '-') {
            return b - c;
        }
        if (o == '*') {
            return b * c;
        }
        return b / c;
    }
    return atof(s[i++]);
}

inline void input() {
    cin.getline(s[0], sizeof(s[0]));
    stringstream ss(s[0]);
    while (ss >> s[n]) {
        ++n;
    }
}

inline void solve() {
    cout << fixed << setprecision(6) << calc(p) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
