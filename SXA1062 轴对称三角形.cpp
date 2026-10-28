#include <bits/stdc++.h>
using namespace std;

int n;
char c;

void row(int i) {
    for (int j = 1; j <= n - i; j++) {
        cout << " ";
    }
    for (int j = 1; j <= 2 * i - 1; j++) {
        cout << "*";
    }
}

void rowb(int i) {
    for (int j = 1; j <= 2 * i - 1; j++) {
        cout << "*";
    }
    for (int j = 1; j <= n - i; j++) {
        cout << " ";
    }
}

signed main() {
    cin >> n >> c;
    if (c == 'x') {
        for (int i = 1; i <= n; i++) {
            row(i);
            cout << "\n";
        }
        for (int i = n - 1; i >= 1; i--) {
            row(i);
            cout << "\n";
        }
    } else {
        for (int i = 1; i <= n; i++) {
            row(i);
            rowb(i);
            cout << "\n";
        }
    }
    return 0;
}
