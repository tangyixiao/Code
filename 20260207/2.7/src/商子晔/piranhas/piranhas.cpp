#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int a[1010];
int d[1010];
int ans;
int llll,rrrr;
int check(){
	for(int i=1;i<=n;i++){
		if(!d[i]&&a[i]) return 0;
	}
	return 1;
}
//我不会剪枝QAQ
void dfs(int step){
	if(step>100) return ;
	if(step>=ans) return ;
	if(check()){
		ans=min(ans,step);
		return ;
	}
	for(int i=llll;i<=rrrr;i++){
		if(a[i]) continue;
		int l=i;
		int r=i;
		while(l>llll-1){
			if(a[l]) break;
			l--;
		}
		while(r<=rrrr){
			if(a[r]) break;
			r++;
		}
		if(r!=n+1&&r-1==i) continue;
		if(l!=0&&l+1==i) continue;
		if(l==0){
			int xr=a[r-1];
			int yr=a[r];
			a[r-1]=a[r];
			a[r]=0;
			dfs(step+1);
			a[r-1]=xr;
			a[r]=yr;
		}else if(r==n+1){
			int xl=a[l];
			int yl=a[l+1];
			a[l+1]=a[l];
			a[l]=0;
			dfs(step+1);
			a[l]=xl;
			a[l+1]=yl;
		}else if(l!=0&&r!=n+1){
			int xr=a[r-1];
			int yr=a[r];
			int xl=a[l];
			int yl=a[l+1];
			a[r-1]=a[r];
			a[r]=0;
			a[l+1]=a[l];
			a[l]=0;
			dfs(step+1);
			a[r-1]=xr;
			a[r]=yr;
			a[l]=xl;
			a[l+1]=yl;
		}
	}
	return ;
}
//奶龙奶龙奶
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("piranhas.in","r",stdin);
	freopen("piranhas.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=0;i<=1007;i++){
			a[i]=0;
			d[i]=0;
		}
		cin>>n>>k;
		for(int i=1;i<=k;i++){
			int x;
			cin>>x;
			a[x]=1;
		}
		for(int i=1;i<=k;i++){
			int x;
			cin>>x;
			d[x]=1;
		}
		if(check()){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(d[i]){
				llll=i;
				break;
			}
		}
		for(int i=n;i>=1;i--){
			if(d[i]){
				rrrr=i;
				break;
			}
		}
		if((llll==1&&(!a[1]))||(rrrr==n&&(!a[n]))){
			cout<<"impoBGible\n";
			continue;
		}
		llll=max(llll-2,1);
		rrrr=min(rrrr+2,n);
		ans=1000000;
		dfs(0);
		if(ans==1000000) cout<<"impoBGible\n";
		else cout<<ans<<"\n";
	}
	return 0;
}
