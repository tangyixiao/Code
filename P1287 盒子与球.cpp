#include <cstdio>
#include <iostream>
using namespace std;
int n, r, f[100][100] = {1};
int jc(int k)
{
    int ans = 1;
    for (int i = 2; i <= k; i++)
    {
        ans *= i;
    }
    return ans;
}
int main()
{
    cin >> n >> r;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            f[i][j] = f[i - 1][j - 1] + j * f[i - 1][j];
        }
    }
    cout << f[n][r] * jc(r);
    return 0;
}
