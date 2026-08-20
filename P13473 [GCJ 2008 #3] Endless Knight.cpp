#include<bits/stdc++.h>
using namespace std;
const int P=10007,N=2e1;
long long r[N],c[N],d[N];
int f[P],g[P];
int q(int a,int b){int z=1;for(;b;b>>=1,a=(long long)a*a%P)if(b&1)z=(long long)z*a%P;return z;}
int C(long long n,long long m){if(m<0||m>n)return 0;int z=1;while(n||m){int a=n%P,b=m%P;if(b>a)return 0;z=(long long)z*f[a]%P*g[b]%P*g[a-b]%P;n/=P;m/=P;}return z;}
int w(long long x,long long y,long long u,long long v){long long a=2*(v-y)-(u-x),b=2*(u-x)-(v-y);if(a<0||b<0||a%3||b%3)return 0;a/=3;b/=3;return C(a+b,a);}
int main(){ios::sync_with_stdio(0);cin.tie(0);f[0]=1;for(int i=1;i<P;i++)f[i]=(long long)f[i-1]*i%P;g[P-1]=q(f[P-1],P-2);for(int i=P-1;i;i--)g[i-1]=(long long)g[i]*i%P;int T;cin>>T;for(int o=1;o<=T;o++){int n;long long h,v;cin>>h>>v>>n;r[0]=c[0]=1;for(int i=1;i<=n;i++)cin>>r[i]>>c[i];r[++n]=h;c[n]=v;for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)if(r[i]+c[i]>r[j]+c[j])swap(r[i],r[j]),swap(c[i],c[j]);d[0]=1;for(int i=1;i<=n;i++){d[i]=w(1,1,r[i],c[i]);for(int j=1;j<i;j++)d[i]=(d[i]-d[j]*w(r[j],c[j],r[i],c[i]))%P;}cout<<"Case #"<<o<<": "<<(d[n]+P)%P<<'\n';}}
