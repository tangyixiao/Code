#include <bits/stdc++.h>

#define M 1000

using namespace std;

int t;
int m, a[M + 5];
int all;
int sum;
int bian[5];
bool flag;

void dfs(int dep) {
    if (flag)
        return;
    if (dep > m) {
        flag = true;
        return;
    }
    for (int i = 1; i <= 4; i++) {
        if (sum - bian[i] >= a[dep]) {
            bian[i] += a[dep];
            dfs(dep + 1);
            bian[i] -= a[dep];
        }
    }
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        all = sum = 0;
        flag = false;
        cin >> m;
        for (int j = 1; j <= m; j++)
            cin >> a[j], all += a[j];
        if (all % 4 != 0) {
            cout << "no" << endl;
            continue;
        }
        sum = all / 4;
        dfs(1);
        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
