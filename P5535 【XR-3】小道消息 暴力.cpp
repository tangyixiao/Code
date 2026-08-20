#include <bits/stdc++.h>
using namespace std;const int N=1005;int d[N],q[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,k,l=0,r=0;cin>>n>>k;memset(d,-1,sizeof d);d[k-1]=0;q[r++]=k-1;while(l<r){int x=q[l++];for(int y=0;y<n;y++)if(d[y]<0&&__gcd(x+2,y+2)==1)d[y]=d[x]+1,q[r++]=y;}cout<<*max_element(d,d+n)<<'\n';}
