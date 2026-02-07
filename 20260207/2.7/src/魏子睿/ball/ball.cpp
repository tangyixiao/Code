#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e5+10;
int res[N];
signed main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	char c;
	int i=1, win=0, lose=0;
	while(cin>>c)
	{
		if(c=='E') break;
		if(c=='W') res[i]=1;
		else res[i]=2;
		i++;
	}
	i=1, win=0, lose=0;
	while(1)
	{
		if(res[i]==1) win++;
		if(res[i]==2) lose++;
		if((win>=11||lose>=11)&&(abs(win-lose)>=2))
		{
			cout<<win<<':'<<lose<<'\n';
			win=0;
			lose=0;
		} 
		if(res[i]==0)
		{
			cout<<win<<':'<<lose<<'\n';
			break;
		}
		i++;
	}
	cout<<'\n';
	i=1, win=0, lose=0;
	while(1)
	{
		if(res[i]==1) win++;
		if(res[i]==2) lose++;
		if((win>=21||lose>=21)&&(abs(win-lose)>=2))
		{
			cout<<win<<':'<<lose<<'\n';
			win=0;
			lose=0;
		} 
		if(res[i]==0)
		{
			cout<<win<<':'<<lose<<'\n';
			break;
		}
		i++;
	}
	return 0;
}
/*
WWWWWWWWWWWWWWWWWWWW
WWLWE
*/
