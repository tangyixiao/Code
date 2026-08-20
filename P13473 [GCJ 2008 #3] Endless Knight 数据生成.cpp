#include<bits/stdc++.h>
using namespace std;
const int N=1e2;
bool a[N][N];
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned s=c>1?stoul(v[1]):chrono::steady_clock::now().time_since_epoch().count();mt19937 g(s);int h=g()%25+1,w=g()%25+1,z=h*w-(h==1&&w==1?1:2),r=g()%(min(6,z)+1);a[1][1]=a[h][w]=1;cout<<1<<'\n'<<h<<' '<<w<<' '<<r<<'\n';while(r--){int x,y;do x=g()%h+1,y=g()%w+1;while(a[x][y]);a[x][y]=1;cout<<x<<' '<<y<<'\n';}}
