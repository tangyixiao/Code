#include<bits/stdc++.h>
using namespace std;
#define int long long
int l,w,h;
int m;
int a[51][51][51];
int vis[51][51][51];
int dirx[11]={1,-1,0,0,0,0};
int diry[11]={0,0,1,-1,0,0};
int dirz[11]={0,0,0,0,1,-1};
int ans;
void dfs(int x,int y,int z){
	if(vis[x][y][z]){
		return ;
	}
	vis[x][y][z]=1;
	for(int i=0;i<6;i++){
		int xx=x+dirx[i];
		int yy=y+diry[i];
		int zz=z+dirz[i];
		if(xx<1||xx>l||yy<1||yy>w||zz<1||zz>h||abs(a[xx][yy][zz]-a[x][y][z])>m||vis[xx][yy][zz]){
			continue;
		}
		dfs(xx,yy,zz);
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("scan.in","r",stdin);
	freopen("scan.out","w",stdout);
	cin>>l>>w>>h>>m;
	for(int i=1;i<=l;i++){
		for(int j=1;j<=w;j++){
			for(int k=1;k<=h;k++){
				cin>>a[i][j][k];
			}
		}
	}
	for(int i=1;i<=l;i++){
		for(int j=1;j<=w;j++){
			for(int k=1;k<=h;k++){
				if(!vis[i][j][k]){
					dfs(i,j,k);
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
//前方啊 没有了方向。

//身上啊 没有了衣裳。

//鲜血啊 渗出了翅膀。

//我的眼泪 湿透了胸膛。

//我常常追忆过去。

//那时，他在澄澈的天空下舒展羽翼。

//高天之上，他与无数沉浮挣扎的灵魂，朝着令人目眩的光明飞去。

//刹那间，万千气流奔涌而来，撕裂的痛楚裹挟着他。

//他拼尽残存之力，伸出在风中颤抖的翅尖

//一切只是绚烂的泡沫，一瞬间无声地破灭。

//风早已偃旗息鼓，染血的翎羽宣告着一切。

//我独自站着，朝着沉默低垂的天空，喉间滚出一支破碎的歌谣。

//他不再飞了。

//那我呢？

//明明，真正的光明，就在前方啊。

//沾着尘泥的、凝着血痂的、负着虚名的……我剥落了最后一片羽毛。

//前方，沸腾着，咆哮着……

//我该在哪里停留？我问我自己。

//纵然带着永远的伤口

//至少我还拥有自由
