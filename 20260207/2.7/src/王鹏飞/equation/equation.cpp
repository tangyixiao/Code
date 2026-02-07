#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+20;
inline int read(){
	int ma=0,f=1;
	char c=getchar();
	while(!('0'<=c&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while(('0'<=c&&c<='9')){ma=(ma<<3)+(ma<<1)+c-'0';c=getchar();}
	return ma*f;
}
inline string intotwo(int x){
	string s;
	while(x){
		if(x%2)s="1"+s;
		else s="0"+s;
		x=x>>1;
	}
	return s;
}
string a[N],s,fd;
inline int find(string t){
	if(t.size()>=s.size())return -1;
	for(int i=0;i<t.size();i++)
		if(i>=s.size()&&t[i]!=s[i])return -1;
	return t.size();
}
inline void sol(){
	unordered_map<string,int>p;
	int n=read(),key=read();
	if(n<3){cout<<0;return ;}
	s=intotwo(key);
	for(int i=1;i<=n;i++){
		int x=read();
		a[i]=intotwo(x);
		
	}
	int ans=0;
	p[a[n-1]+a[n]]++;
	for(int i=n-2;i>=1;i--){
		int t=find(a[i]);
		if(t!=-1){
			fd=s.substr(t,s.size()-a[i].size());
			if(p.count(fd))ans+=p[fd];
		}
		for(int j=i+1;j<=n;j++)p[a[i]+a[j]]++;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("equation.in","r",stdin);freopen("equation.out","w",stdout);
	int t;cin>>t;while(t--)sol();
}
