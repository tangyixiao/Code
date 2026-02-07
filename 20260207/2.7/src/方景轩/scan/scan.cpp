#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1;
int l,w,h;
int m,ans;
int u[N];
signed main(){
	freopen("scan.in","r",stdin);
	freopen("scan.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>l>>w>>h;
	cin>>m;
	int v=l*w*h;
	for(int i=1;i<=v;i++){
		int a;
		cin>>a;
		u[a]++;
	}
	for(int i=0;i<=255;i++){
		if(u[i]>0){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
