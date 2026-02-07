#include<bits/stdc++.h>
using namespace std;
inline read(){
	int ma=0,f=1;
	char c=getchar();
	while(!('0'<=c&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while(('0'<=c&&c<='9')){ma=(ma<<3)+(ma<<1)+c-'0';}
	return ma*f;
}
int sb[60][60][60];
int vis[60][60][60];
int cha, l,m,n;
int d[3][6]={{0,0,0,0,1,-1},{1,-1,0,0,0,0},{0,0,1,-1,0,0}};
inline void dfs(int x,int y,int z){
	for(int i=0;i<6;i++){
		int xx=d[0][i]+x;
		int yy=d[1][i]+y;
		int zz=d[2][i]+z;
		if(1<=xx&&xx<=l&&1<=yy&&yy<=m&&1<=zz&&zz<=n&&!vis[xx][yy][zz])
			if(abs(sb[x][y][z]-sb[xx][yy][zz])<=cha){
				vis[xx][yy][zz]=1;
				dfs(xx,yy,zz);
			}
	}
}
signed main(){
	freopen("scan.in","r",stdin);freopen("scan.out","w",stdout);
	cin >>l>>m>>n>>cha;
	for(int i=1;i<=l;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				cin >>sb[i][j][k];
	int ans=0;
	for(int i=1;i<=l;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				if(!vis[i][j][k]){
					ans++;
					vis[i][j][k]=1;
					dfs(i,j,k);
				}	
	cout<<ans<<"\n";
}
