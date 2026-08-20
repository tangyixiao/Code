#include<bits/stdc++.h>
using namespace std;
const int N=2e1;
int a[N];
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned s=c>1?stoul(v[1]):chrono::steady_clock::now().time_since_epoch().count();mt19937 g(s);int n=g()%10+2,m=g()%15+1;for(int i=1;i<=n;i++)a[i]=g()&1;cout<<n<<' '<<m<<'\n';while(m--){int x=g()%n+1,y=g()%n+1;while(y==x)y=g()%n+1;int w=a[x]^a[y];if((g()%20)==0)w^=1;cout<<(w?'D':'S')<<' '<<x<<' '<<y<<'\n';}}
