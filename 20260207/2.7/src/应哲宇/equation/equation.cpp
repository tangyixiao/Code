#include<bits/stdc++.h>
#define int long long 
using namespace std;
string a[100005],s,fd;
int st1[100005],st2[100005],n,p,cnt1,cnt2,x;
string er(int x){
	string s;
	while(x){
		if(x%2)s="1"+s;
		else s="0"+s;
		x=x>>1;
	}
	return s;
}
bool fnd(string t){
	if(t.size()>=s.size())return 0;
	for(int i=0;i<t.size();i++)
		if(i>=s.size()&&t[i]!=s[i])return 0;
	return t.size();
}
bool fid(string t){
	if(t.size()>=s.size())return 0;
	for(int i=t.size()-1,j=s.size()-1;i>=0;i--)
		if(t[i]!=s[i])return 0;
	return 1;
}
signed main(){
	freopen("equation.in","r",stdin);
	freopen("equation.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>p;
		if(n<3){
			cout<<0;
			break;
		}
		s=er(p);
		for(int i=1;i<=n;i++){
			cin>>x;
			a[i]=er(x);
			if(fnd(a[i])) st1[++cnt1]=i;
			if(fid(a[i])) st2[++cnt2]=i;
		}
		int ans=0;
		for(int i=1;i<=cnt1;i++)
			for(int j=1;j<=cnt2;j++){
				if(st1[i]>st2[j]) continue;
				if(s.size()-a[st1[i]].size()-a[st2[j]].size()<=0) continue;
				string pp=s.substr(a[st1[i]].size(),s.size()-a[st1[i]].size()-a[st2[j]].size());
				for(int k=st1[i]+1;k<st2[j];k++)
					if(a[k]==pp) ans++;
			}
		cout<<ans<<"\n";
	}
}
