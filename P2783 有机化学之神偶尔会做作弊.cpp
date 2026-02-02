#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
vector<int> G1[10010];
bool vis[10010];
int id,dfn[10010],low[10010];
stack<int> s;
int k,mp[10010];
void tar(int u,int fa) {
	vis[u]=1;
	low[u]=dfn[u]=++id;
	s.push(u);
	for(int v:G1[u])
		if(v!=fa) {
			if(!dfn[v]) {
				tar(v,u);
				low[u]=min(low[v],low[u]);
			} else if(vis[v])
				low[u]=min(dfn[v],low[u]);
		}
	if(low[u]==dfn[u]) {
		k++;
		for(int v=s.top(); v!=u; s.pop(),v=s.top()) {
			mp[v]=k;
			vis[v]=0;
		}
		mp[u]=k;
		vis[u]=0;
		s.pop();
	}
	return;
}
vector<int> G2[10010];
int T;
int a,b;
int dis[10010];
queue<int> q;
void bfs() {
	memset(dis,0x3f,sizeof(dis));
	dis[a]=1;
	q.push(a);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int v:G2[u])
			if(dis[v]>dis[u]+1) {
				dis[v]=dis[u]+1;
				q.push(v);
			}
	}
	return;
}
void print(int a) {
	if(a>=2)
		print(a>>1);
	cout<<(a&1);
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1,u,v; i<=m; i++) {
		cin>>u>>v;
		G1[u].push_back(v);
		G1[v].push_back(u);
	}
//	for(int i=1; i<=n; i++)
//		if(!dfn[i])
	tar(1,0);
	for(int i=1; i<=n; i++) {
		for(int j:G1[i])
			if(mp[i]!=mp[j])
				G2[mp[i]].push_back(mp[j]);
	}
	cin>>T;
	while(T--) {
		cin>>a>>b;
		a=mp[a];
		b=mp[b];
		bfs();
		print(dis[b]);
		cout<<'\n';
	}
	return 0;
}
