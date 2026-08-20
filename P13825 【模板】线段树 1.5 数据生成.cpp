#include<bits/stdc++.h>
using namespace std;
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned s=c>1?stoul(v[1]):chrono::steady_clock::now().time_since_epoch().count();mt19937 g(s);int n=g()%20+1,m=g()%40+1;cout<<n<<' '<<m<<'\n';while(m--){int o=g()%2+1,l=g()%n+1,r=g()%n+1;if(l>r)swap(l,r);cout<<o<<' '<<l<<' '<<r;if(o==1)cout<<' '<<g()%20+1;cout<<'\n';}}
