#include<bits/stdc++.h>
using namespace std;
const int N=50;
const int dx[]={1,0,-1,0,0,0},dy[]={0,1,0,-1,0,0},dz[]={0,0,0,0,1,-1};
int l,r,h,m,ans,vis[N][N][N],val[N][N][N];
bool check(int x,int y,int z){
    if(x<1||y<1||z<1||x>l||y>r||z>h)return true;
    return false;
}
void dfs(int x,int y,int z){
    vis[x][y][z]=1;
    for(int i=0;i<6;i++){
        int nx=x+dx[i],ny=y+dy[i],nz=z+dz[i];
        if(check(nx,ny,nz))continue;
        if(vis[nx][ny][nz])continue;
        if(abs(val[nx][ny][nz]-val[x][y][z])>m)
            continue;
        dfs(nx,ny,nz);
    }
}
signed main(){
    freopen("scan.in","r",stdin);
    freopen("scan.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>l>>r>>h>>m;
    for(int z=1;z<=h;z++)
        for(int x=1;x<=l;x++)
            for(int y=1;y<=r;y++)
                cin>>val[x][y][z];
    if(!(l*r*h)){
        cout<<0<<'\n';
        return 0;
    }
    for(int z=1;z<=h;z++)
        for(int x=1;x<=l;x++)
            for(int y=1;y<=r;y++)
                if(!vis[x][y][z])
                    ans++,dfs(x,y,z);
    cout<<ans<<'\n';
    return 0;
}
/*
2 2 2
0
1 1 1 1 2 2 2 2

*/