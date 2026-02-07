#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e5+10;
unordered_map<int, vector<int>> mp;
int a[N], s[N];
vector<int> v[5];
int ans=0;
void dfs(int x, int k)
{
	if(x>3)
	{
		if(k) return ;
		int cnt=0;
		for(int i=v[2].size()-1;i>=0;i--)
		{
			while(v[3].size()&&v[3].back()>=v[2][i]) v[3].pop_back();
			s[i]=v[3].size();
			cnt+=s[i];
		}
		int j=v[2].size()-1;
		for(int i=v[1].size()-1;i>=0;i--)
		{
			while(j>=0&&v[2][j]>=v[1][i]) cnt-=s[j], j--;
			ans+=cnt;
		}
		return ;
	}
	int len=log2(k), cnt=0;
	for(int i=0;i<=len;i++)
	{
		cnt+=k&(1<<i);
		if(((k>>i)&1)&&mp.count(cnt)) v[x]=mp[cnt], dfs(x+1, (k-cnt)>>(i+1));
	}
}
signed main()
{
	freopen("equation.in", "r", stdin);
	freopen("equation.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		mp.clear();
		int n, k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i], mp[a[i]].push_back(i);
		dfs(1, k);
		cout<<ans<<'\n';
	} 
	return 0;
}
