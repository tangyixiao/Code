#include<iostream>
#include<cmath>
using namespace std;
int l,w,h;
int m;
int map[60][60][60];
bool vis[69][60][60];
int tx[7]= {0,1,-1,0,0,0,0},
           ty[7]= {0,0,0,1,-1,0,0},
                  tz[7]= {0,0,0,0,0,1,-1};
void dfs(int x,int y,int z) {
	for(int i=1; i<=6; i++) {
		int a=x+tx[i],b=y+ty[i],c=z+tz[i];
		if(a>=1&&a<=l&&b>=1&&b<=w&&c>=1&&c<=h)
			if(abs(map[a][b][c]-map[x][y][z])<=m&&!vis[a][b][c]) {
				vis[a][b][c]=1;
				dfs(a,b,c);
			}
	}
	return;
}
int ans;
int main() {
	freopen("scan.in","r",stdin);
	freopen("scan.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>l>>w>>h>>m;
	for(int i=1; i<=l; i++)
		for(int j=1; j<=w; j++)
			for(int k=1; k<=h; k++)
				cin>>map[i][j][k];
	for(int i=1; i<=l; i++)
		for(int j=1; j<=w; j++)
			for(int k=1; k<=h; k++)
				if(!vis[i][j][k]) {
					dfs(i,j,k);
					ans++;
				}
	cout<<ans;
	return 0;
}
