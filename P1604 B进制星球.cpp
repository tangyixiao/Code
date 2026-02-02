#include <bits/stdc++.h>
using namespace std;
char a[2005], b[2005];
int n, pos = 2001, aa[2005], bb[2005], sum[2005];
int main() {
    cin >> n >> a >> b;
    for (int l = 0, r = strlen(a) - 1; l <= r; l++, r--) {
        swap(a[l], a[r]);
    }
    for (int l = 0, r = strlen(b) - 1; l <= r; l++, r--) {
        swap(b[l], b[r]);
    }
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] >= 'A' && a[i] <= 'Z')
            aa[i + 1] = a[i] - 'A' + 10;
        else
            aa[i + 1] = a[i] - '0';
    }
    for (int i = 0; i < strlen(b); i++) {
        if (b[i] >= 'A' && b[i] <= 'Z')
            bb[i + 1] = b[i] - 'A' + 10;
        else
            bb[i + 1] = b[i] - '0';
    }
    for (int i = 1; i <= 2000; i++)
        sum[i] = aa[i] + bb[i];
    for (int i = 1; i <= 2000; i++)
        if (sum[i] >= n)
            sum[i] -= n, sum[i + 1]++;
    while (sum[pos] == 0 && pos > 0)
        pos--;
    for (int i = pos; i >= 1; i--) {
        if (sum[i] >= 10)
            cout << char(sum[i] - 10 + 'A');
        else
            cout << sum[i];
    }
    return 0;
}
