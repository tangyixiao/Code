#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
inline void solve() {
    for (;;) {
        system("fc P10475.out P10475.ans");
        Sleep(10000);
    }
    return;
}

signed main() {
    freopen("P10475.ans", "w", stdout);
    srand(time(0));
    int r = rand() % 10001 + 1, c = rand() % 86 + 1;
    cout << r << " " << c << "\n";
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (rand() % 2) {
                cout << "A";
            } else {
                cout << "B";
            }
        }
        cout << "\n";
    }
    return 0;
}