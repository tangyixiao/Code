#include<bits/stdc++.h>
#define int long long
using namespace std;
int l,w,h;
int m,ans;
int g[110][110][110];
bool vs[110][110][110];
int dx[6]={1,-1,0,0,0,0},dy[6]={0,0,1,-1,0,0},dz[6]={0,0,0,0,1,-1};
struct nnd{
	int x,y,z;
};
queue<nnd> q;
signed main(){
	freopen("scan.in","r",stdin);
	freopen("scan.out","w",stdout);
	scanf("%lld %lld %lld",&l,&w,&h);
	scanf("%lld",&m);
	for(int i=1;i<=l;i++){
		for(int j=1;j<=w;j++){
			for(int k=1;k<=h;k++){
				scanf("%lld",&g[i][j][k]);
			}
		}
	}
	for(int i=1;i<=l;i++){
		for(int j=1;j<=w;j++){
			for(int k=1;k<=h;k++){
				if(!vs[i][j][k]){
					ans++;
					vs[i][j][k]=1;
					q.push((nnd){i,j,k});
					while(!q.empty()){
						nnd t=q.front();
						q.pop();
						int x=t.x,y=t.y,z=t.z;
						for(int o=0;o<6;o++){
							int xx=x+dx[o],yy=y+dy[o],zz=z+dz[o];
							if(xx>=1&&xx<=l&&yy>=1&&yy<=w&&zz>=1&&zz<=h&&!vs[xx][yy][zz]&&abs(g[xx][yy][zz]-g[x][y][z])<=m){
								vs[xx][yy][zz]=1;
								q.push((nnd){xx,yy,zz});
							}
						}
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}