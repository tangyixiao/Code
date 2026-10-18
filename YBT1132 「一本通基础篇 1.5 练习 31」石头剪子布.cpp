#include <bits/stdc++.h>
using namespace std;

const int N = 3;
char s[N][10] = {"Rock", "Scissors", "Paper"};
int n;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        char a[10], b[10];
        cin >> a >> b;
        int x = 0, y = 0;
        for (int j = 0; j < N; j++) {
            if (strcmp(a, s[j]) == 0) {
                x = j;
            }
            if (strcmp(b, s[j]) == 0) {
                y = j;
            }
        }
        cout << (x == y ? "Tie" : (x + 1) % N == y ? "Player1"
                                                   : "Player2")
             << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}