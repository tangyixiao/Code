#include<iostream>
#include<cstring>
using namespace std;
int C,T;
int n,m;
int p[1010],d[1010];
int ans;
bool flag;
void dfs(int k) {
	if(k>ans)
		return;
	bool res=1;
	for(int i=1; i<=m; i++)
		if(p[i]!=d[i]) {
			res=0;
			break;
		}
	if(res) {
		flag=1;
		return;
	}
	for(int i=1; i<=n; i++) {
		int x=0,y=m+1,t=1;
		for(int j=1; j<=m; j++) {
			if(p[j]<i)
				x=j;
			if(p[j]==i-1||p[j]==i)
				t=0;
			if(p[j]>i)
				break;
		}
		for(int j=m; j>=1; j--) {
			if(p[j]>i)
				y=i;
			if(p[j]==i+1||p[j]==i)
				t=0;
			if(p[j]<i)
				break;
		}
		if(!t)
			continue;
		p[x]++;
		p[y]--;
		dfs(k+1);
		p[x]--;
		p[y]++;
	}
	return;
}
int main() {
	freopen("piranhas.in","r",stdin);
	freopen("piranhas.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	if(C>=8) {
		for(int i=1; i<=T; i++)
			cout<<"impossible\n";
		return 0;
	}
	while(T--) {
		cin>>n>>m;
		for(int i=1; i<=m; i++)
			cin>>p[i];
		for(int i=1; i<=m; i++)
			cin>>d[i];
		flag=0;
		for(ans=0; ans<=65; ans++) {
			dfs(0);
			if(flag)
				break;
		}
		if(flag)
			cout<<ans<<'\n';
		else
			cout<<"impossible\n";
	}
	return 0;
}
