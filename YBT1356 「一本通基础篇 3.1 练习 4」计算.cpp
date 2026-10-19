#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int n, x;
char s[N];

inline void input() {
    cin >> s;
    n = strlen(s);
    return;
}

inline int e();

inline int p() {
    int v = 0;
    while (x < n && s[x] >= '0' && s[x] <= '9') {
        v = v * 10 + s[x] - '0', x++;
    }
    return v;
}

inline int r() {
    if (x < n && s[x] == '(') {
        x++;
        int v = e();
        x++;
        return v;
    }
    return p();
}

inline int u() {
    if (x < n && (s[x] == '-' || s[x] == '+')) {
        char c = s[x++];
        int v = u();
        return c == '-' ? -v : v;
    }
    return r();
}

inline int w() {
    int v = u();
    while (x < n && s[x] == '^') {
        x++;
        v = (int)pow(v, u());
    }
    return v;
}

inline int m() {
    int v = w();
    while (x < n && (s[x] == '*' || s[x] == '/')) {
        char c = s[x++];
        int t = w();
        v = c == '*' ? v * t : v / t;
    }
    return v;
}

inline int e() {
    int v = m();
    while (x < n && (s[x] == '+' || s[x] == '-')) {
        char c = s[x++];
        int t = m();
        v = c == '+' ? v + t : v - t;
    }
    return v;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    cout << e() << "\n";
    return 0;
}