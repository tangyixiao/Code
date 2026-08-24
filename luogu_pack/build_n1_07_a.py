from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=2097152;const double P=acos(-1);complex<double>a[N],b[N];int r[N],d[N];char s[1000005],t[1000005];void f(complex<double>*a,int n,int o){for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);for(int l=2;l<=n;l<<=1){complex<double>w(cos(2*P/l),o*sin(2*P/l));for(int i=0;i<n;i+=l){complex<double>x(1);for(int j=0;j<l/2;j++,x*=w){auto u=a[i+j],v=x*a[i+j+l/2];a[i+j]=u+v;a[i+j+l/2]=u-v;}}}if(o<0)for(int i=0;i<n;i++)a[i]/=n;}int main(){ios::sync_with_stdio(0);cin.tie(0);cin>>s>>t;int n=strlen(s),m=strlen(t),l=1,k=0;while(l<n+m)l<<=1;while((1<<k)<l)k++;for(int i=0;i<n;i++)a[i]=s[n-1-i]-48;for(int i=0;i<m;i++)b[i]=t[m-1-i]-48;for(int i=1;i<l;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));f(a,l,1);f(b,l,1);for(int i=0;i<l;i++)a[i]*=b[i];f(a,l,-1);long long c=0;for(int i=0;i<l;i++){c+=llround(a[i].real());d[i]=c%10;c/=10;}while(c)d[l++]=c%10,c/=10;while(l>1&&!d[l-1])l--;while(l--)cout<<d[l];cout<<'\n';}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;const int N=2000005;int a[N],b[N],c[N];char s[1000005],t[1000005];int main(){ios::sync_with_stdio(0);cin.tie(0);cin>>s>>t;int n=strlen(s),m=strlen(t);for(int i=0;i<n;i++)a[i]=s[n-1-i]-48;for(int i=0;i<m;i++)b[i]=t[m-1-i]-48;for(int i=0;i<n;i++)for(int j=0;j<m;j++)c[i+j]+=a[i]*b[j];for(int i=0;i<n+m;i++)c[i+1]+=c[i]/10,c[i]%=10;int l=n+m;while(l>1&&!c[l-1])l--;while(l--)cout<<c[l];cout<<'\n';}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):1000000;mt19937_64 g(s);z=min(1000000ULL,max(1ULL,z));for(int q=0;q<2;q++){int n=g()%z+1;cout<<g()%9+1;while(--n)cout<<g()%10;cout<<'\n';}}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;const int N=256;const double P=acos(-1);complex<double>a[N],b[N];int r[N],x[N],y[N],z[N],o[N];void f(complex<double>*a,int n,int q){for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);for(int l=2;l<=n;l<<=1){complex<double>w(cos(2*P/l),q*sin(2*P/l));for(int i=0;i<n;i+=l){complex<double>t(1);for(int j=0;j<l/2;j++,t*=w){auto u=a[i+j],v=t*a[i+j+l/2];a[i+j]=u+v;a[i+j+l/2]=u-v;}}}if(q<0)for(int i=0;i<n;i++)a[i]/=n;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%30+1,m=g()%30+1,l=1,k=0;while(l<n+m)l<<=1;while((1<<k)<l)k++;memset(a,0,sizeof a);memset(b,0,sizeof b);memset(z,0,sizeof z);memset(o,0,sizeof o);for(int i=0;i<n;i++)x[i]=g()%10,a[i]=x[i];for(int i=0;i<m;i++)y[i]=g()%10,b[i]=y[i];for(int i=1;i<l;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));for(int i=0;i<n;i++)for(int j=0;j<m;j++)o[i+j]+=x[i]*y[j];for(int i=0;i<l-1;i++)o[i+1]+=o[i]/10,o[i]%=10;f(a,l,1);f(b,l,1);for(int i=0;i<l;i++)a[i]*=b[i];f(a,l,-1);long long c=0;for(int i=0;i<l;i++)c+=llround(a[i].real()),z[i]=c%10,c/=10;for(int i=0;i<l;i++)if(z[i]!=o[i])return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P1919','P1919 【模板】高精度乘法 _ A_B Problem 升级版',r'''把两个十进制串倒序作为多项式系数。补到二次幂长度后做两次 FFT，逐点相乘并逆变换，四舍五入得到每一位的卷积值，最后从低位向高位统一进位。

长度不超过 $2^{21}$，复杂度 $O(n\log n)$，空间复杂度 $O(n)$。''',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},parts=[AB],extra=[('1\n1\n','1\n'),('999\n999\n','998001\n'),('123456789\n987654321\n','121932631112635269\n'),('100000000000000000000\n100000000000000000000\n','10000000000000000000000000000000000000000\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;const int N=262144,P=998244353,G=3;int a[N],b[N],c[N],d[N],r[N];int q(int a,int b=P-2){int s=1;for(;b;b>>=1,a=1LL*a*a%P)if(b&1)s=1LL*s*a%P;return s;}void f(int*a,int n,int o){for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);for(int l=2;l<=n;l<<=1){int w=q(G,(P-1)/l);if(o<0)w=q(w);for(int i=0;i<n;i+=l)for(int j=0,x=1;j<l/2;j++,x=1LL*x*w%P){int u=a[i+j],v=1LL*x*a[i+j+l/2]%P;a[i+j]=(u+v)%P;a[i+j+l/2]=(u-v+P)%P;}}if(o<0){int x=q(n);for(int i=0;i<n;i++)a[i]=1LL*a[i]*x%P;}}int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>a[i];b[0]=q(a[0]);for(int k=1;k<n;k<<=1){int l=k<<1,L=k<<2,z=__builtin_ctz(L);for(int i=0;i<L;i++)c[i]=i<l&&i<n?a[i]:0,d[i]=i<k?b[i]:0,r[i]=(r[i>>1]>>1)|((i&1)<<(z-1));f(c,L,1);f(d,L,1);for(int i=0;i<L;i++)d[i]=1LL*d[i]*(2-1LL*c[i]*d[i]%P+P)%P;f(d,L,-1);for(int i=0;i<l&&i<n;i++)b[i]=d[i];}for(int i=0;i<n;i++)cout<<b[i]<<' ';cout<<'\n';}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;const int N=100005,P=998244353;int a[N],b[N];int q(int a,int n=P-2){int r=1;for(;n;n>>=1,a=1LL*a*a%P)if(n&1)r=1LL*r*a%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>a[i];b[0]=q(a[0]);for(int i=1;i<n;i++){long long s=0;for(int j=1;j<=i;j++)s+=1LL*a[j]*b[i-j]%P;b[i]=(P-s%P)*1LL*b[0]%P;}for(int i=0;i<n;i++)cout<<b[i]<<' ';cout<<'\n';}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100000;mt19937_64 g(s);int n=g()%min(100000ULL,max(1ULL,z))+1;cout<<n<<'\n'<<g()%998244352+1<<' ';while(--n)cout<<g()%998244353<<' ';cout<<'\n';}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;const int N=256,P=998244353,G=3;int a[N],b[N],c[N],d[N],r[N],o[N];int q(int a,int n=P-2){int s=1;for(;n;n>>=1,a=1LL*a*a%P)if(n&1)s=1LL*s*a%P;return s;}void f(int*a,int n,int z){for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);for(int l=2;l<=n;l<<=1){int w=q(G,(P-1)/l);if(z<0)w=q(w);for(int i=0;i<n;i+=l)for(int j=0,x=1;j<l/2;j++,x=1LL*x*w%P){int u=a[i+j],v=1LL*x*a[i+j+l/2]%P;a[i+j]=(u+v)%P;a[i+j+l/2]=(u-v+P)%P;}}if(z<0){int x=q(n);for(int i=0;i<n;i++)a[i]=1LL*a[i]*x%P;}}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%60+1;memset(a,0,sizeof a);memset(b,0,sizeof b);memset(o,0,sizeof o);for(int i=0;i<n;i++)a[i]=g()%P;b[0]=o[0]=q(a[0]?a[0]:(a[0]=1));for(int i=1;i<n;i++){long long x=0;for(int j=1;j<=i;j++)x+=1LL*a[j]*o[i-j]%P;o[i]=(P-x%P)*1LL*o[0]%P;}for(int k=1;k<n;k<<=1){int l=k<<1,L=k<<2,z=__builtin_ctz(L);for(int i=0;i<L;i++)c[i]=i<l&&i<n?a[i]:0,d[i]=i<k?b[i]:0,r[i]=(r[i>>1]>>1)|((i&1)<<(z-1));f(c,L,1);f(d,L,1);for(int i=0;i<L;i++)d[i]=1LL*d[i]*(2-1LL*c[i]*d[i]%P+P)%P;f(d,L,-1);for(int i=0;i<l&&i<n;i++)b[i]=d[i];}for(int i=0;i<n;i++)if(b[i]!=o[i])return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P4238','P4238 【模板】多项式乘法逆',r'''设已经求出 $B(x)$ 满足 $AB\equiv1\pmod{x^k}$。牛顿迭代

$$B\leftarrow B(2-AB)\pmod{x^{2k}}$$

把正确项数翻倍。每轮用 NTT 完成乘法，直到覆盖前 $n$ 项。

复杂度 $O(n\log n)$，空间复杂度 $O(n)$。''',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},parts=[BB],extra=[('1\n1\n','1\n'),('4\n2 3 4 5\n','499122177 748683264 873463809 935854081\n'),('5\n1 1 1 1 1\n','1 998244352 0 0 0\n'),('3\n7 0 2\n','855638017 0 611170012\n')])

C=r'''#include <bits/stdc++.h>
using namespace std;const int N=262144,A=998244353,B=1004535809,C=469762049;int a[N],b[N],x[N],y[N],r[N],u[N],v[N],n,m,p;int q(int a,int b,int P){int s=1;for(;b;b>>=1,a=1LL*a*a%P)if(b&1)s=1LL*s*a%P;return s;}void f(int*a,int n,int z,int P){for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);for(int l=2;l<=n;l<<=1){int w=q(3,(P-1)/l,P);if(z<0)w=q(w,P-2,P);for(int i=0;i<n;i+=l)for(int j=0,t=1;j<l/2;j++,t=1LL*t*w%P){int U=a[i+j],V=1LL*t*a[i+j+l/2]%P;a[i+j]=(U+V)%P;a[i+j+l/2]=(U-V+P)%P;}}if(z<0){int t=q(n,P-2,P);for(int i=0;i<n;i++)a[i]=1LL*a[i]*t%P;}}void g(int P,int*o,int l){for(int i=0;i<l;i++)x[i]=i<=n?a[i]%P:0,y[i]=i<=m?b[i]%P:0;f(x,l,1,P);f(y,l,1,P);for(int i=0;i<l;i++)x[i]=1LL*x[i]*y[i]%P;f(x,l,-1,P);if(o)memcpy(o,x,l*sizeof(int));}int main(){ios::sync_with_stdio(0);cin.tie(0);cin>>n>>m>>p;for(int i=0;i<=n;i++)cin>>a[i];for(int i=0;i<=m;i++)cin>>b[i];int l=1,k=0;while(l<=n+m)l<<=1;while((1<<k)<l)k++;for(int i=1;i<l;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));g(A,u,l);g(B,v,l);g(C,0,l);long long I=q(A%B,B-2,B),J=q(1LL*A*B%C,C-2,C);for(int i=0;i<=n+m;i++){long long s=(v[i]-u[i]+B)%B*I%B,t=(x[i]-(u[i]+A%C*s)%C+C)%C*J%C;long long z=(u[i]%p+(__int128)(A%p)*(s%p)+(__int128)(A%p)*(B%p)%p*(t%p))%p;cout<<z<<' ';}cout<<'\n';}
'''
CB=r'''#include <bits/stdc++.h>
using namespace std;const int N=200005;long long a[N],b[N],c[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m,p;cin>>n>>m>>p;for(int i=0;i<=n;i++)cin>>a[i];for(int i=0;i<=m;i++)cin>>b[i];for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)c[i+j]=(c[i+j]+a[i]*b[j])%p;for(int i=0;i<=n+m;i++)cout<<c[i]<<' ';cout<<'\n';}
'''
CG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100000;mt19937_64 g(s);int n=g()%min(100000ULL,max(1ULL,z))+1,m=g()%min(100000ULL,max(1ULL,z))+1,p=g()%1000000008+2;cout<<n<<' '<<m<<' '<<p<<'\n';for(int i=0;i<=n;i++)cout<<g()%1000000001<<' ';cout<<'\n';for(int i=0;i<=m;i++)cout<<g()%1000000001<<' ';cout<<'\n';}
'''
CS=r'''#include <bits/stdc++.h>
using namespace std;const int N=256,A=998244353,B=1004535809,C=469762049;int a[N],b[N],x[N],y[N],r[N],u[N],v[N],o[N],n,m,p;int q(int a,int b,int P){int s=1;for(;b;b>>=1,a=1LL*a*a%P)if(b&1)s=1LL*s*a%P;return s;}void f(int*a,int n,int z,int P){for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);for(int l=2;l<=n;l<<=1){int w=q(3,(P-1)/l,P);if(z<0)w=q(w,P-2,P);for(int i=0;i<n;i+=l)for(int j=0,t=1;j<l/2;j++,t=1LL*t*w%P){int U=a[i+j],V=1LL*t*a[i+j+l/2]%P;a[i+j]=(U+V)%P;a[i+j+l/2]=(U-V+P)%P;}}if(z<0){int t=q(n,P-2,P);for(int i=0;i<n;i++)a[i]=1LL*a[i]*t%P;}}void h(int P,int*o,int l){for(int i=0;i<l;i++)x[i]=i<=n?a[i]%P:0,y[i]=i<=m?b[i]%P:0;f(x,l,1,P);f(y,l,1,P);for(int i=0;i<l;i++)x[i]=1LL*x[i]*y[i]%P;f(x,l,-1,P);if(o)memcpy(o,x,l*sizeof(int));}int main(int D,char**w){ios::sync_with_stdio(0);cin.tie(0);int R=D>1?stoi(w[1]):1000;unsigned long long s0=D>2?stoull(w[2]):1;mt19937_64 g(s0);while(R--){n=g()%40+1;m=g()%40+1;p=g()%1000000008+2;int l=1,k=0;while(l<=n+m)l<<=1;while((1<<k)<l)k++;memset(o,0,sizeof o);for(int i=0;i<=n;i++)a[i]=g()%1000000001;for(int i=0;i<=m;i++)b[i]=g()%1000000001;for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)o[i+j]=(o[i+j]+1LL*a[i]*b[j])%p;for(int i=1;i<l;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));h(A,u,l);h(B,v,l);h(C,0,l);long long I=q(A%B,B-2,B),J=q(1LL*A*B%C,C-2,C);for(int i=0;i<=n+m;i++){long long S=(v[i]-u[i]+B)%B*I%B,T=(x[i]-(u[i]+A%C*S)%C+C)%C*J%C,Z=(u[i]%p+(__int128)(A%p)*(S%p)+(__int128)(A%p)*(B%p)%p*(T%p))%p;if(Z!=o[i])return cout<<"WA\n",1;}}cout<<"OK\n";}
'''
add('P4245','P4245 【模板】任意模数多项式乘法',r'''分别在三个 NTT 质数下计算卷积。真实系数小于

$$10^5(10^9)^2<998244353\times1004535809\times469762049,$$

因此三个余数唯一确定真实整数系数。用 Garner 的混合进位形式依次求出第二、第三位，再直接对题目给定的任意模数取模；给定模数不需要是质数。

复杂度 $O((n+m)\log(n+m))$，空间复杂度 $O(n+m)$。''',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},parts=[CB],extra=[('1 1 7\n1 2\n3 4\n','3 3 1\n'),('1 1 1000000007\n1000000000 999999999\n888888888 777777777\n','777777833 444444548 777777833\n'),('2 2 12\n0 1 2\n4 0 5\n','0 4 8 5 10\n')])
