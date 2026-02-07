#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1010;
int n,m,a[N],b[N],c[N],d[N];
inline void solve(){
	cin>>m>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		c[i]=b[i]-a[i];
	}
	int ans=0;
	d[1]=1;
	for(int i=0;i<=n;++i){
		if(b[i]-d[i]<0&&i!=1) {
			cout<<"impoBGible\n";
			return;
		}
		ans+=b[i]-d[i];
		d[i+1]=a[i+1]-(b[i]-d[i]);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("piranhas.in","r",stdin);
	freopen("piranhas.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int kcm,t; cin>>kcm>>t;
	while(t--) solve();
	return 0;
}