#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int n, x;
char s[N];

inline void input() {
    cin >> s;
    for (int i = 0; i < N; i++) {
        if (s[i] == '@') {
            s[i] = 0;
            break;
        }
    }
    n = strlen(s);
    return;
}

inline int e();

inline int r() {
    if (s[x] == '(') {
        x++;
        int v = e();
        x++;
        return v;
    }
    int v = 0;
    while (x < n && s[x] >= '0' && s[x] <= '9') {
        v = v * 10 + s[x] - '0', x++;
    }
    return v;
}

inline int u() {
    if ((s[x] == '-' || s[x] == '+') && (x == 0 || s[x - 1] == '(' || s[x - 1] == '+' || s[x - 1] == '-' || s[x - 1] == '*' || s[x - 1] == '/' || s[x - 1] == '^')) {
        char c = s[x++];
        int v = u();
        return c == '-' ? -v : v;
    }
    return r();
}

inline int w() {
    int v = u();
    while (s[x] == '^') {
        x++;
        v = (int)pow(v, u());
    }
    return v;
}

inline int m() {
    int v = w();
    while (s[x] == '*' || s[x] == '/') {
        char c = s[x++];
        int t = w();
        v = c == '*' ? v * t : v / t;
    }
    return v;
}

inline int e() {
    int v = m();
    while (s[x] == '+' || s[x] == '-') {
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
    int v = e();
    if (x != n) {
        cout << "NO\n";
        return 0;
    }
    cout << v << "\n";
    return 0;
}