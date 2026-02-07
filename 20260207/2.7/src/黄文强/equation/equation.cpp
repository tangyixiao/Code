#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline void read(int &x){
	char c; while((c=getchar())<48||c>57);
	for(x=0;c>47&&c<58;c=getchar())x=x*10+(c^48);
}
inline void read(ll &x){
	char c; while((c=getchar())<48||c>57);
	for(x=0;c>47&&c<58;c=getchar())x=x*10+(c^48);
}
const int N=100005;
int n,lg2[(1<<20)+5],per[25]={1};
ll a[N],b[N],c[N],p;
unordered_map<ll,int>mp;
// inline string g(ll p){
	// string s="";
	// for(;p;p>>=1) s=(char)((p&1ll)+48)+s;
	// return s;
// }
ll ans;
// unordered_map<string,vector<int>>m;

// inline void merge(string s1,string s2,string s3){
	// for(int i=0,l1=m[s1].size();i<l1;++i){
		// for(int j=m[s2].size()-1;~j;--j){
			// if(m[s1][i]>m[s2][j]) break;
			// for(int k=m[s3].size()-1;~k;--k){
				// if(m[s3][k]<m[s1][i]||m[s3][k]<m[s2][j]) break;
				// ++ans;
				// // cerr<<m[s1][i]<<' '<<m[s2][j]<<' '<<m[s3][k]<<'\n';
			// }
		// }
	// }
// }
inline void solve(){	
	// int n; ll P,a;
	ans=0;
	// cin>>n>>P;
	// read(n); read(P);
	read(n); read(p);
	mp.clear();
	// m.clear();
	// string p=g(P); int len=p.size();
	// cerr<<p<<'\n';
	// for(int i=1;i<=n;++i){
		// // cin>>a;
		// read(a);
		// m[g(a)].push_back(i);
		// // cerr<<g(a)<<'\n';
	// }
	// string I="",J="",K="";
	// for(int i=0;i<len-2;++i){
		// J=K="";
		// I+=p[i];
		// if(m[I].size()==0) continue;
		// for(int j=i+1;j<len-1;++j){
			// J+=p[j];
			// if(m[J].size()==0) continue;
			// K="";
			// for(int k=j+1;k<len;++k) K+=p[k];
			// if(m[K].size()==0) continue;
			// merge(I,J,K);
		// }
	// }
	for(int i=1;i<=n;++i){
		// cin>>a[i];
		read(a[i]);
		b[i]=per[lg2[a[i]]];
		c[i]=a[i]-b[i];
		ll kkk=(p-c[i])/b[i];
		if(kkk*b[i]+c[i]==p) mp[kkk]=i;
	}
	for(int i=1;i<=n-2;++i){
		for(int j=i+1;j<=n-1;++j){
			ll kkk=4*b[i]*b[j]+4*c[i]*b[j]+2*b[j]+2*c[j]+1;
			if(mp[kkk]>j) ++ans;
			// for(int k=j+1;k<=n;++k){
				// if(a[i]*4*b[j]*b[k]+a[j]*2*b[k]+a[k]==p){
					// ++ans;
				// }
			// }
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("equation.in","r",stdin);
	freopen("equation.out","w",stdout);
	// ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i=2;i<=(1<<20);++i) lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=20;++i) per[i]=per[i-1]<<1;
	int t; 
	// cin>>t;
	read(t);
	while(t--) solve();
	return 0;
}