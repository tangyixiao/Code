#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5;

string n, a;
int s, top;

inline void input() {
    cin >> n >> s;
    for (int i = 0; i < (int)n.size(); i++) {
        while (top > 0 && s > 0 && a[top - 1] > n[i]) {
            top--, s--;
        }
        a[top++] = n[i];
    }
    while (s > 0 && top > 0) {
        top--, s--;
    }
    while (top > 0 && a[0] == '0') {
        top--;
    }
    if (!top) {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < top; i++) {
        cout << a[i];
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    return 0;
}
