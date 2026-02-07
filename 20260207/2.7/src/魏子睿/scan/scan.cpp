#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[55][55][55], dirx[]={1, -1, 0, 0, 0, 0}, diry[]={0, 0, 1, -1, 0, 0}, dirz[]={0, 0, 0, 0, 1, -1};
int id[55][55][55];
int n, m, h, maxv, cnt=0;
void dfs(int x, int y, int z)
{
	for(int i=0;i<6;i++)
	{
		int nx=x+dirx[i], ny=y+diry[i], nz=z+dirz[i];
		if(nx<1||nx>n||ny<1||ny>m||nz<1||nz>h) continue;
		if(id[nx][ny][nz]==id[x][y][z]&&abs(a[nx][ny][nz]-a[x][y][z])>maxv)
			id[nx][ny][nz]=++cnt, dfs(nx, ny, nz);
		else if(!id[nx][ny][nz]&&abs(a[nx][ny][nz]-a[x][y][z])<=maxv)
			id[nx][ny][nz]=id[x][y][z], dfs(nx, ny, nz);
	}
}
signed main()
{
	freopen("scan.in", "r", stdin);
	freopen("scan.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>h>>maxv;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=h;k++)
				cin>>a[i][j][k];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=h;k++)
				if(!id[i][j][k]) id[i][j][k]=++cnt, dfs(i, j, k);
	cout<<cnt<<'\n';
	return 0;
}
/*
2 2 2
0
1 1 1 1 2 2 2 2

2 2 1
1
0 2 1 1

2 2 2
1
0 1 2 2 1 1 1 0
*/
