#include <bits/stdc++.h>
#define N 30
using namespace std;
bool flag, used[N];
int n, a[5][N], num[N];
char s[5][N];
bool check() {
    int add = 0;
    for (int i = n; i >= 1; i--) {
        int A, B, C;
        A = num[a[1][i]], B = num[a[2][i]], C = num[a[3][i]];
        if ((A + B + add) % n != C)
            return false;
        add = (A + B + add) / n;
    }
    return true;
}
bool Prune() {
    if (num[a[1][1]] + num[a[2][1]] >= n)
        return true;
    for (int i = n - 1; i >= 0; i--) {
        int A = num[a[1][i]], B = num[a[2][i]], C = num[a[3][i]];
        if (A == -1 || B == -1 || C == -1)
            continue;
        if ((A + B) % n != C && (A + B + 1) % n != C)
            return true;
    }
    return false;
}
void Print() {
    for (int i = 1; i <= n; i++)
        printf("%d ", num[i]);
    return;
}
bool Check() {
    for (int i = 1; i <= n; i++)
        if (num[i] == -1)
            return false;
    return true;
}
void dfs(int x, int y, int t) {
    if (flag)
        return;
    if (Prune())
        return;
    if (Check()) {
        if (check()) {
            Print();
            flag = true;
        }
        return;
    }
    if (num[a[y][x]] == -1) {
        for (int i = n - 1; i >= 0; i--) {
            if (!used[i]) {
                if (y != 3) {
                    num[a[y][x]] = i;
                    used[i] = true;
                    dfs(x, y + 1, t);
                    used[i] = false;
                    num[a[y][x]] = -1;
                } else {
                    int z = num[a[1][x]] + num[a[2][x]] + t;
                    if (z % n != i)
                        continue;
                    used[i] = true;
                    num[a[y][x]] = i;
                    dfs(x - 1, 1, z / n);
                    used[i] = false;
                    num[a[y][x]] = -1;
                }
            }
        }
    } else {
        if (y != 3)
            dfs(x, y + 1, t);
        else {
            int z = num[a[1][x]] + num[a[2][x]] + t;
            if (Prune())
                return;
            dfs(x - 1, 1, z / n);
        }
    }
    return;
}
void Getid() {
    for (int i = 1; i <= 3; i++)
        for (int j = 0; j < n; j++)
            a[i][j + 1] = s[i][j] - 'A' + 1;
    return;
}
int main() {
    scanf("%d", &n);
    scanf("%s%s%s", s[1], s[2], s[3]);
    Getid();
    memset(num, -1, sizeof(num));
    dfs(n, 1, 0);
    return 0;
}
