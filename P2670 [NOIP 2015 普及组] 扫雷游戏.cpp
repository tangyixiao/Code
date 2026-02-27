#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
const int N = 105;
char mp[N][N];
int n, m;
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)

        {
            if (mp[i][j] != '*')
            {

                int cnt = 0;
                for (int k = 0; k < 8; k++)
                {
                    cnt += (mp[i + dx[k]][j + dy[k]] == '*');
                }
                cout << cnt;
            }
            else
            {
                cout << "*";
            }
        }
        cout << "\n";
    }
    return 0;
}