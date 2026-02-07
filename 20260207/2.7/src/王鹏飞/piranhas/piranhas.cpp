#include<bits/stdc++.h>
using namespace std;
int C,T,n,k,ans,p[3005],d[3005];
bool check(){
	for(int i=1;i<=k;i++){
		if(p[i]!=d[i]) return 0;
	}
	return 1;
} 
inline int findl(int x){
	int ma=-1;
	for(int i=1;i<=n;i++)
		if(p[i]<x)ma=p[i];
	else return ma;
	return ma;
}
inline int findr(int x){
	int ma=-1;
	for(int i=n;i>=1;i--)
		if(p[i]>x)ma=p[i];
	else return ma;
	return ma;
}
void dfs(int step){
	if(check()==1){
		ans=min(ans,step);
		return;
	}
	for(int i=1;i<=k;i++){
		int l=findl(p[i]),r=findr(p[i]);
		for(int j=1;j<=k;j++){
			if(p[l]+j>p[i])break;
			if(p[r]-j>p[i])break;
			p[l]+=j;p[r]-=j;
			dfs(step+1);
			p[l]-=j;p[r]+=j;
		}
	}
}
int main(){
	freopen("piranhas.in","r",stdin);
	freopen("piranhas.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=k;i++) cin>>p[i];
		for(int i=1;i<=k;i++) cin>>d[i];
		ans=INT_MAX;
		sort(p+1,p+1+k);
		sort(d+1,d+1+k);
		dfs(0);
		cout<<ans<<endl;
	}
} 
