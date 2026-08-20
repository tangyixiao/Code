#include <bits/stdc++.h>
using namespace std;const int N=100005;int p[N],v[N];long long f[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,k=0;long long r=0;cin>>n;f[1]=1;for(int i=2;i<=n;i++){if(!v[i])p[k++]=i,f[i]=i-1;for(int j=0;j<k&&i*p[j]<=n;j++){v[i*p[j]]=1;if(i%p[j]==0){f[i*p[j]]=f[i]*p[j];break;}f[i*p[j]]=f[i]*(p[j]-1);}}for(int i=1;i<=n;i++)r+=f[i]*(n/i)*(n/i);cout<<r<<'\n';}
