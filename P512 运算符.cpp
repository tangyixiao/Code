#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, ns, el;
long long cnt;
char expr[200];
char sol[25][200];

void wnum(int v) {
    char b[10];
    int p = 0;
    while (v > 0) {
        b[p++] = '0' + v % 10;
        v /= 10;
    }
    for (int i = p - 1; i >= 0; i--) {
        expr[el++] = b[i];
    }
    expr[el] = 0;
}

void dfs(int i, long long acc, long long term, int op) {
    if (i == n) {
        if (acc + op * term == 0) {
            cnt++;
            if (ns < 20) {
                for (int j = 0; j <= el; j++) {
                    sol[ns][j] = expr[j];
                }
                ns++;
            }
        }
        return;
    }
    int nx = i + 1, save = el, p = 1, t = nx;
    while (t > 0) {
        p *= 10;
        t /= 10;
    }
    expr[el++] = ' ';
    expr[el++] = '+';
    expr[el++] = ' ';
    wnum(nx);
    dfs(nx, acc + op * term, nx, 1);
    el = save;
    expr[el] = 0;
    expr[el++] = ' ';
    expr[el++] = '-';
    expr[el++] = ' ';
    wnum(nx);
    dfs(nx, acc + op * term, nx, -1);
    el = save;
    expr[el] = 0;
    expr[el++] = ' ';
    expr[el++] = '.';
    expr[el++] = ' ';
    wnum(nx);
    dfs(nx, acc, term * p + nx, op);
    el = save;
    expr[el] = 0;
}

signed main() {
    scanf("%d", &n);
    el = 0;
    wnum(1);
    dfs(1, 0, 1, 1);
    for (int i = 0; i < ns; i++) {
        printf("%s\n", sol[i]);
    }
    printf("%lld\n", cnt);
    return 0;
}
