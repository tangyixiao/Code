//将三个数二进制拼在一起
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &x){
	char c; while((c=getchar())<'0'||c>'9');
	for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+(c^48);
}
int T;
int n,p,ans;
int a[1000010],mxn;
vector<int> g[1100000];
signed main(){
	freopen("equation.in","r",stdin);
	freopen("equation.out","w",stdout);
	read(T);
	while(T--){
		mxn=0;
		read(n),read(p);
		for(int i=1;i<=n;i++){
			read(a[i]);
			g[a[i]].push_back(i);
			mxn=max(mxn,a[i]);
		}
		int pl=floor(log2(p))+1;
		mxn=min((int)floor(log2(mxn))+1,pl);
		for(int ln=1;ln<=mxn;ln++){
			for(int l=1;l+ln<pl;l++){
				// cout<<l<<endl<<ln<<endl<<pl-l-ln<<endl;
				int pp=p;
				int x=pp>>(pl-l);
				int y=(pp>>(pl-l-ln))-((pp>>(pl-l))<<ln);
				// pp>>=len;
				int z=pp-(y<<(pl-ln-l))-(x<<(pl-l));
				// cout<<x<<' '<<y<<' '<<z<<endl;
				if(x<0||y<0||z<0) continue;
				int lx=g[x].size(),ly=g[y].size(),lz=g[z].size();
				if(lx==0||ly==0||lz==0) continue;
				for(int i=0;i<lx;i++){
					for(int j=0;j<ly;j++){
						for(int k=0;k<lz;k++){
							if(g[x][i]<g[y][j]&&g[y][j]<g[z][k]){
								// cout<<g[x][i]<<endl<<g[y][j]<<endl<<g[z][k]<<endl;
								ans++;
							}
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}