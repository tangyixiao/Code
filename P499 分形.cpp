#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char a[N][N];
int n, s;

void draw(int x, int y, int d) {
    if (d == 1) {
        a[x][y] = 'X';
        return;
    }
    int t = d / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((i + j) % 2 == 0) {
                draw(x + i * t, y + j * t, t);
            }
        }
    }
}

signed main() {
    cin >> n;
    s = 1;
    for (int i = 1; i < n; i++) {
        s *= 3;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = ' ';
        }
    }
    draw(0, 0, s);
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}