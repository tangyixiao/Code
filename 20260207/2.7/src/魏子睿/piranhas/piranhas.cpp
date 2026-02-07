#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1005], b[1005], id[1005];
int n, k, ans=1e9;
bool check()
{
	for(int i=1;i<=k;i++)
		if(a[i]!=b[i]) return false;
	return true;
}
void dfs(int cur)
{
	if(cur>=ans) return ;
	if(check())
	{
		ans=cur;
		return ;
	}
	if(cur>20) return ;
	for(int i=1;i<=n;i++)
	{
		if(id[i]||id[i-1]||id[i+1]) continue;
		int tmp1=0, tmp2=0, j1=0, j2=0;
		for(int j=i-2;j>=1;j--)
		{
			if(id[j])
			{
				j1=j;
				tmp1=id[j];
				id[j]=0;
				a[tmp1]++;
				id[a[tmp1]]=tmp1;
				break;
			}
		}
		for(int j=i+2;j<=n;j++)
		{
			if(id[j])
			{
				j2=j;
				tmp2=id[j];
				id[j]=0;
				a[tmp2]--;
				id[a[tmp2]]=tmp2;
				break;
			}
		}
		dfs(cur+1);
		if(tmp1)
		{
			id[a[tmp1]]=0;
			a[tmp1]--;
			id[j1]=tmp1;
		}
		if(tmp2)
		{
			id[a[tmp2]]=0;
			a[tmp2]--;
			id[j2]=tmp2;
		}
	}
}
signed main()
{
	freopen("piranhas.in", "r", stdin);
	freopen("piranhas.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin>>c>>t;
	while(t--)
	{
		ans=1e9;
		cin>>n>>k;
		for(int i=1;i<=k;i++)
			cin>>a[i], id[a[i]]=i;
		for(int i=1;i<=k;i++)
			cin>>b[i];
		dfs(0);
		if(ans==1e9) cout<<"impoBGible\n";
		else cout<<ans<<'\n';
	}
	return 0;
}
