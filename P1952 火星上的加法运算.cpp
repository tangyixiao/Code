#include <bits/stdc++.h>
using namespace std;
char a[205], b[205];
int n, pos = 201, aa[205], bb[205], sum[205];
int main()
{
    cin >> n >> a >> b;
    for (int l = 0, r = strlen(a) - 1; l <= r; l++, r--)
        swap(a[l], a[r]);
    for (int l = 0, r = strlen(b) - 1; l <= r; l++, r--)
        swap(b[l], b[r]);
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
            aa[i + 1] = a[i] - 'a' + 10;
        else
            aa[i + 1] = a[i] - '0';
    }
    for (int i = 0; i < strlen(b); i++)
    {
        if (b[i] >= 'a' && b[i] <= 'z')
            bb[i + 1] = b[i] - 'a' + 10;
        else
            bb[i + 1] = b[i] - '0';
    }
    for (int i = 1; i <= 200; i++)
        sum[i] = aa[i] + bb[i];
    for (int i = 1; i <= 200; i++)
        if (sum[i] >= n)
            sum[i] -= n, sum[i + 1]++;
    while (sum[pos] == 0 && pos > 0)
        pos--;
    for (int i = pos; i >= 1; i--)
    {
        if (sum[i] >= 10)
            cout << char(sum[i] - 10 + 'a');
        else
            cout << sum[i];
    }
    return 0;
}
