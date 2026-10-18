#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, k, a[N], b[N];

inline void input() {
    cin >> n >> k;
}

inline void solve() {
    input();
    int t = n - 2, w = 2 * n - 1, r = t * t - k;
    for (int i = t - 1; i >= 0; i--) {
        int c = w - 4 - 2 * i, s = min(r, c);
        a[i] = s, r -= s;
    }
    r = k;
    for (int j = t - 1; j >= 0; j--) {
        int c = 2 * j + 1, s = min(r, c);
        b[j] = s, r -= s;
    }
    for (int i = 0; i < w; i++) {
        cout << "-";
    }
    cout << "\n";
    for (int i = 0; i < t; i++) {
        int c = w - 4 - 2 * i;
        for (int j = 0; j <= i; j++) {
            cout << " ";
        }
        cout << "\\";
        for (int j = 0; j < c - a[i]; j++) {
            cout << " ";
        }
        for (int j = 0; j < a[i]; j++) {
            cout << "*";
        }
        cout << "/" << "\n";
    }
    for (int j = 0; j < t; j++) {
        int c = 2 * j + 1;
        for (int i = 0; i < t - j; i++) {
            cout << " ";
        }
        cout << "/";
        for (int i = 0; i < c - b[j]; i++) {
            cout << " ";
        }
        for (int i = 0; i < b[j]; i++) {
            cout << "*";
        }
        cout << "\\" << "\n";
    }
    for (int i = 0; i < w; i++) {
        cout << "-";
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}