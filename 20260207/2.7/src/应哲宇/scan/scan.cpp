#include<bits/stdc++.h>
using namespace std;
int n,m,l,M,mp[55][55][55],ans;
bool vis[55][55][55]; 
int dx[]={0,1,-1,0,0,0};
int dy[]={1,0,0,-1,0,0};
int dh[]={0,0,0,0,1,-1};
void dfs(int x,int y,int h){
	for(int i=0;i<6;i++){
		int bx=x+dx[i],by=y+dy[i],bh=h+dh[i];
		if(bx<1||bx>n||by<1||by>m||bh<1||bh>l) continue;
		if(vis[bx][by][bh]==1||abs(mp[x][y][h]-mp[bx][by][bh])>M) continue;
		vis[bx][by][bh]=1; 
		dfs(bx,by,bh);
	}
}
int main(){
	freopen("scan.in","r",stdin);
	freopen("scan.out","w",stdout);
	cin>>n>>m>>l>>M;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=l;k++)
				cin>>mp[i][j][k];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=l;k++){
				if(vis[i][j][k]==0){
					dfs(i,j,k);
					ans++;
				}
			}
	cout<<ans<<endl;
} 