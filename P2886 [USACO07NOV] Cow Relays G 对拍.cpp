#include <bits/stdc++.h>
using namespace std;
const long long I=4e18;long long a[9][9],b[9][9],c[9][9],d[9][9],e[9][9],f[9],g[9];
void m(long long a[9][9],long long b[9][9],long long c[9][9],int n){for(int i=0;i<n;i++)for(int j=0;j<n;j++)d[i][j]=I;for(int i=0;i<n;i++)for(int k=0;k<n;k++)for(int j=0;j<n;j++)d[i][j]=min(d[i][j],a[i][k]+b[k][j]);memcpy(c,d,sizeof d);}
int main(int c0,char**v){ios::sync_with_stdio(0);cin.tie(0);int r=c0>1?stoi(v[1]):1000;unsigned long long s=c0>2?stoull(v[2]):1;mt19937_64 q(s);while(r--){int n=q()%10+1,k=q()%7+2;for(int i=0;i<k;i++)for(int j=0;j<k;j++)e[i][j]=a[i][j]=i==j?I:q()%30+1,b[i][j]=i==j?0:I;int z=n;for(;z;z>>=1,m(a,a,a,k))if(z&1)m(b,a,b,k);fill(f,f+k,I);f[0]=0;for(int z=0;z<n;z++){fill(g,g+k,I);for(int i=0;i<k;i++)for(int j=0;j<k;j++)g[j]=min(g[j],f[i]+e[i][j]);copy(g,g+k,f);}if(b[0][k-1]!=f[k-1])return cout<<"WA\n",1;}cout<<"OK\n";}
