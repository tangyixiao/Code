#include<bits/stdc++.h>
using namespace std;
int g[55][55][55],v[55][55][55];
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
int L,W,H,M,cnt;
void dfs(int x,int y,int z){
	v[x][y][z]=1;
	for(int i=0;i<6;i++){
		int nx=x+dx[i],ny=y+dy[i],nz=z+dz[i];
		if(nx>=1&&nx<=L&&ny>=1&&ny<=W&&nz>=1&&nz<=H&&!v[nx][ny][nz]&&abs(g[nx][ny][nz]-g[x][y][z])<=M)
			dfs(nx,ny,nz);
	}
}
int main(){
	freopen("scan.in","r",stdin);
	freopen("scan.out","w",stdout);
	scanf("%d%d%d%d",&L,&W,&H,&M);
	for(int x=1;x<=L;x++)
		for(int y=1;y<=W;y++)
			for(int z=1;z<=H;z++)
				scanf("%d",&g[x][y][z]);
	for(int x=1;x<=L;x++)
		for(int y=1;y<=W;y++)
			for(int z=1;z<=H;z++)
				if(!v[x][y][z]){
					cnt++;
					dfs(x,y,z);
				}
	printf("%d\n",cnt);
	return 0;
}

