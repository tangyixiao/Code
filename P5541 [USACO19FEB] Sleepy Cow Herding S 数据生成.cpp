#include<bits/stdc++.h>
using namespace std;
const int N=1e2;
int a[N];
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned s=c>1?stoul(v[1]):chrono::steady_clock::now().time_since_epoch().count();mt19937 g(s);int n=g()%18+3;for(int i=0;i<n;i++){do a[i]=g()%80+1;while(find(a,a+i,a[i])!=a+i);}cout<<n<<'\n';for(int i=0;i<n;i++)cout<<a[i]<<'\n';}
