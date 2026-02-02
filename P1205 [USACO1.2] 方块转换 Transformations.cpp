#include <bits/stdc++.h>
using namespace std;
int n;
char sta[15][15], old[15][15], now[15][15], ed[15][15];

void in() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sta[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ed[i][j];
        }
    }
}
void f() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            now[i][j] = old[i][j] = sta[i][j];
        }
    }
}
bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (now[i][j] != ed[i][j])
                return false;
    }
    return true;
}
void turn90() {
    for (int i = 0, k = n - 1; i < n; i++, k--) {
        for (int j = 0; j < n; j++) {
            now[j][k] = old[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            old[i][j] = now[i][j];
        }
    }
}
void revers() {
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j <= k; j++, k--) {
            now[i][j] = old[i][k];
            now[i][k] = old[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            old[i][j] = now[i][j];
        }
    }
}
void turn180() {
    turn90();
    turn90();
}
void turn270() {
    turn180();
    turn90();
}
bool comb() {
    revers();
    turn90();
    if (check())
        return true;
    f();

    revers();
    turn180();
    if (check())
        return true;
    f();

    revers();
    turn270();
    if (check())
        return true;
    f();

    return false;
}
int main() {
    cin >> n;
    in();
    f();
    turn90();
    if (check()) {
        cout << 1;
        return 0;
    }
    f();

    turn180();
    if (check()) {
        cout << 2;
        return 0;
    }
    f();

    turn270();
    if (check()) {
        cout << 3;
        return 0;
    }
    f();

    revers();
    if (check()) {
        cout << 4;
        return 0;
    }
    f();

    if (comb()) {
        cout << 5;
        return 0;
    }
    f();

    if (check()) {
        cout << 6;
        return 0;
    }
    cout << 7;
    return 0;
}
