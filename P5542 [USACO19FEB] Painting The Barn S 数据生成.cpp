#include<bits/stdc++.h>
using namespace std;
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned s=c>1?stoul(v[1]):chrono::steady_clock::now().time_since_epoch().count();mt19937 g(s);int n=g()%8+1,k=g()%n+1;cout<<n<<' '<<k<<'\n';while(n--){int x=g()%10,y=g()%10,u=x+g()%(10-x)+1,w=y+g()%(10-y)+1;cout<<x<<' '<<y<<' '<<u<<' '<<w<<'\n';}}
