#include <bits/stdc++.h>
using namespace std;
const int L = 1001;
string add(string a, string b) {
    string ans;
    int na[L] = {0}, nb[L] = {0};
    int la = a.size(), lb = b.size();
    for (int i = 0; i < la; i++)
        na[la - 1 - i] = a[i] - '0';
    for (int i = 0; i < lb; i++)
        nb[lb - 1 - i] = b[i] - '0';
    int lmax = la > lb ? la : lb;
    for (int i = 0; i < lmax; i++)
        na[i] += nb[i], na[i + 1] += na[i] / 10, na[i] %= 10;
    if (na[lmax])
        lmax++;
    for (int i = lmax - 1; i >= 0; i--)
        ans += na[i] + '0';
    return ans;
}
int na[L];
string mul(string a, int b) {
    string ans;
    int La = a.size();
    fill(na, na + L, 0);
    for (int i = La - 1; i >= 0; i--)
        na[La - i - 1] = a[i] - '0';
    int w = 0;
    for (int i = 0; i < La; i++)
        na[i] = na[i] * b + w, w = na[i] / 10, na[i] = na[i] % 10;
    while (w)
        na[La++] = w % 10, w /= 10;
    La--;
    while (La >= 0)
        ans += na[La--] + '0';
    return ans;
}
int n, m;
string f[101][101];
int main() {
    for (int i = 1; i <= 100; i++)
        f[i][1] = "1";
    for (int i = 2; i <= 100; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = add(f[i - 1][j - 1], mul(f[i - 1][j], j));
    while (cin >> n >> m) {
        if (n < m)
            printf("0\n");
        else
            cout << f[n][m] << endl;
    }
    return 0;
}
