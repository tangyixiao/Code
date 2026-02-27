#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
char ans[40], s[40];
int K, check[10], dis[10][10], t[10];

void times(int tmp) {
    int l = strlen(ans), x = 0, cnt = 0;
    if (tmp == 10) {
        for (int i = l; i > 0; i--)
            ans[i] = ans[i - 1];
        ans[0] = '0';
    } else {
        for (int i = 0; i < l; i++) {
            x = (ans[i] - '0') * tmp + cnt;
            cnt = x;
            if (x >= 10) {
                x %= 10;
            }
            ans[i] = x + '0';
            cnt = (cnt - x) / 10;
        }
        if (cnt)
            ans[l] = cnt + '0';
    }
}
int main() {
    scanf("%s %d", s, &K);
    int L = strlen(s);
    for (int i = 0; i < L; i++)
        check[s[i] - '0']++;
    ans[0] = '1';
    memset(dis, 0, sizeof(dis));

    for (int i = 1; i <= K; i++) {
        int a, b;
        cin >> a >> b;
        dis[a][b] = 1;
    }

    for (int k = 0; k <= 9; k++) {
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                if (dis[i][j] || (dis[i][k] && dis[k][j]))
                    dis[i][j] = 1;
            }
        }
    }
    for (int i = 0; i <= 9; i++)
        dis[i][i] = 0;
    for (int i = 0; i <= 9; i++) {
        int tmp = 1;
        for (int j = 0; j <= 9; j++) {
            if (dis[i][j] && check[i])
                tmp++;
        }
        if (s[0] - '0' == i && dis[i][0])
            tmp--;
        t[i] = tmp;
    }
    for (int i = 0; i < L; i++)
        if (t[s[i] - '0'])
            times(t[s[i] - '0']);

    int L_ = strlen(ans);
    for (int i = L_ - 1; i >= 0; i--)
        cout << ans[i];
    return 0;
}
