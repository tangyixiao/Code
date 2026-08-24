from build_lib import R,add,w

def en(b,d,i,o,h):
 s=(R/(b+'.md')).read_text().split('## English Statement',1)[0]
 s+=f'''## English Statement

### Description

{d}

### Input

{i}

### Output

{o}

### Constraints

{h}'''
 w(b+'.md',s)

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=262144,P=998244353,G=3;int f0[N],g0[N],q0[N],r0[N],a[N],b[N],v[N];int q(int a,int n=P-2){int r=1;for(;n;n>>=1,a=1LL*a*a%P)if(n&1)r=1LL*r*a%P;return r;}void t(int*a,int n,int z){for(int i=0;i<n;i++)if(i<v[i])swap(a[i],a[v[i]]);for(int l=2;l<=n;l<<=1){int w=q(G,(P-1)/l);if(z<0)w=q(w);for(int i=0;i<n;i+=l)for(int j=0,x=1;j<l/2;j++,x=1LL*x*w%P){int u=a[i+j],y=1LL*x*a[i+j+l/2]%P;a[i+j]=(u+y)%P;a[i+j+l/2]=(u-y+P)%P;}}if(z<0){int x=q(n);for(int i=0;i<n;i++)a[i]=1LL*a[i]*x%P;}}void h(int*s,int*d,int n){d[0]=q(s[0]);for(int k=1;k<n;k<<=1){int l=k<<1,z=__builtin_ctz(l);for(int i=0;i<l;i++)a[i]=i<n?s[i]:0,b[i]=i<k?d[i]:0;for(int i=1;i<l;i++)v[i]=(v[i>>1]>>1)|((i&1)<<(z-1));t(a,l,1);t(b,l,1);for(int i=0;i<l;i++)b[i]=1LL*b[i]*(2-1LL*a[i]*b[i]%P+P)%P;t(b,l,-1);for(int i=k;i<l&&i<n;i++)d[i]=b[i];}}int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;for(int i=0;i<=n;i++)cin>>f0[i];for(int i=0;i<=m;i++)cin>>g0[i];int k=n-m+1;for(int i=0;i<k;i++)r0[i]=i<=m?g0[m-i]:0;h(r0,q0,k);int l=1,z=0;while(l<2*k-1)l<<=1;while((1<<z)<l)z++;for(int i=0;i<l;i++)a[i]=i<k?f0[n-i]:0,b[i]=i<k?q0[i]:0;for(int i=1;i<l;i++)v[i]=(v[i>>1]>>1)|((i&1)<<(z-1));t(a,l,1);t(b,l,1);for(int i=0;i<l;i++)a[i]=1LL*a[i]*b[i]%P;t(a,l,-1);for(int i=0;i<k;i++)q0[i]=a[k-1-i];l=1;z=0;while(l<=n)l<<=1;while((1<<z)<l)z++;for(int i=0;i<l;i++)a[i]=i<k?q0[i]:0,b[i]=i<=m?g0[i]:0;for(int i=1;i<l;i++)v[i]=(v[i>>1]>>1)|((i&1)<<(z-1));t(a,l,1);t(b,l,1);for(int i=0;i<l;i++)a[i]=1LL*a[i]*b[i]%P;t(a,l,-1);for(int i=0;i<m;i++)r0[i]=(f0[i]-a[i]+P)%P;for(int i=0;i<k;i++)cout<<q0[i]<<' ';cout<<'\n';for(int i=0;i<m;i++)cout<<r0[i]<<' ';cout<<'\n';}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;const int N=100005,P=998244353;int f[N],g[N],q[N];int z(int a,int n=P-2){int r=1;for(;n;n>>=1,a=1LL*a*a%P)if(n&1)r=1LL*r*a%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;for(int i=0;i<=n;i++)cin>>f[i];for(int i=0;i<=m;i++)cin>>g[i];int v=z(g[m]);for(int i=n-m;i>=0;i--){q[i]=1LL*f[i+m]*v%P;for(int j=0;j<=m;j++)f[i+j]=(f[i+j]-1LL*q[i]*g[j]%P+P)%P;}for(int i=0;i<=n-m;i++)cout<<q[i]<<' ';cout<<'\n';for(int i=0;i<m;i++)cout<<f[i]<<' ';cout<<'\n';}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;const int N=100005,P=998244353;int a[N],b[N];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100000;mt19937_64 g(s);z=min(100000ULL,max(2ULL,z));int n=g()%(z-1)+2,m=g()%(n-1)+1;cout<<n<<' '<<m<<'\n';for(int i=0;i<=n;i++)a[i]=g()%P;for(int i=0;i<=m;i++)b[i]=g()%P;b[m]=g()%(P-1)+1;for(int i=0;i<=n;i++)cout<<a[i]<<' ';cout<<'\n';for(int i=0;i<=m;i++)cout<<b[i]<<' ';cout<<'\n';}
'''
AG=AG.replace('for(int i=0;i<=m;i++)b[i]=g()%P;','a[n]=g()%(P-1)+1;for(int i=0;i<=m;i++)b[i]=g()%P;')
AS=r'''#include <bits/stdc++.h>
using namespace std;const int N=128,P=998244353,G=3;int f0[N],g0[N],q0[N],r0[N],a[N],b[N],v[N],o0[N],o1[N];int q(int a,int n=P-2){int r=1;for(;n;n>>=1,a=1LL*a*a%P)if(n&1)r=1LL*r*a%P;return r;}void t(int*a,int n,int z){for(int i=0;i<n;i++)if(i<v[i])swap(a[i],a[v[i]]);for(int l=2;l<=n;l<<=1){int w=q(G,(P-1)/l);if(z<0)w=q(w);for(int i=0;i<n;i+=l)for(int j=0,x=1;j<l/2;j++,x=1LL*x*w%P){int u=a[i+j],y=1LL*x*a[i+j+l/2]%P;a[i+j]=(u+y)%P;a[i+j+l/2]=(u-y+P)%P;}}if(z<0){int x=q(n);for(int i=0;i<n;i++)a[i]=1LL*a[i]*x%P;}}void h(int*s,int*d,int n){d[0]=q(s[0]);for(int k=1;k<n;k<<=1){int l=k<<1,z=__builtin_ctz(l);for(int i=0;i<l;i++)a[i]=i<n?s[i]:0,b[i]=i<k?d[i]:0;for(int i=1;i<l;i++)v[i]=(v[i>>1]>>1)|((i&1)<<(z-1));t(a,l,1);t(b,l,1);for(int i=0;i<l;i++)b[i]=1LL*b[i]*(2-1LL*a[i]*b[i]%P+P)%P;t(b,l,-1);for(int i=k;i<l&&i<n;i++)d[i]=b[i];}}void s(int n,int m){int k=n-m+1;for(int i=0;i<k;i++)r0[i]=i<=m?g0[m-i]:0;h(r0,q0,k);int l=1,z=0;while(l<2*k-1)l<<=1;while((1<<z)<l)z++;for(int i=0;i<l;i++)a[i]=i<k?f0[n-i]:0,b[i]=i<k?q0[i]:0;for(int i=1;i<l;i++)v[i]=(v[i>>1]>>1)|((i&1)<<(z-1));t(a,l,1);t(b,l,1);for(int i=0;i<l;i++)a[i]=1LL*a[i]*b[i]%P;t(a,l,-1);for(int i=0;i<k;i++)q0[i]=a[k-1-i];l=1;z=0;while(l<=n)l<<=1;while((1<<z)<l)z++;for(int i=0;i<l;i++)a[i]=i<k?q0[i]:0,b[i]=i<=m?g0[i]:0;for(int i=1;i<l;i++)v[i]=(v[i>>1]>>1)|((i&1)<<(z-1));t(a,l,1);t(b,l,1);for(int i=0;i<l;i++)a[i]=1LL*a[i]*b[i]%P;t(a,l,-1);for(int i=0;i<m;i++)r0[i]=(f0[i]-a[i]+P)%P;}int main(int c,char**w){ios::sync_with_stdio(0);cin.tie(0);int R=c>1?stoi(w[1]):1000;unsigned long long z=c>2?stoull(w[2]):1;mt19937_64 g(z);while(R--){int n=g()%30+2,m=g()%(n-1)+1;memset(q0,0,sizeof q0);memset(r0,0,sizeof r0);memset(o0,0,sizeof o0);for(int i=0;i<=n;i++)f0[i]=o1[i]=g()%P;for(int i=0;i<=m;i++)g0[i]=g()%P;g0[m]=g()%(P-1)+1;int x=q(g0[m]);for(int i=n-m;i>=0;i--){o0[i]=1LL*o1[i+m]*x%P;for(int j=0;j<=m;j++)o1[i+j]=(o1[i+j]-1LL*o0[i]*g0[j]%P+P)%P;}s(n,m);for(int i=0;i<=n-m;i++)if(q0[i]!=o0[i])return cout<<"WA\n",1;for(int i=0;i<m;i++)if(r0[i]!=o1[i])return cout<<"WA\n",1;}cout<<"OK\n";}
'''
O='int l=k<<1,z=__builtin_ctz(l);for(int i=0;i<l;i++)a[i]=i<n?s[i]:0,b[i]=i<k?d[i]:0;for(int i=1;i<l;i++)v[i]=(v[i>>1]>>1)|((i&1)<<(z-1));t(a,l,1);t(b,l,1);for(int i=0;i<l;i++)b[i]=1LL*b[i]*(2-1LL*a[i]*b[i]%P+P)%P;t(b,l,-1);for(int i=k;i<l&&i<n;i++)d[i]=b[i];'
V='int l=k<<1,L=k<<2,z=__builtin_ctz(L);for(int i=0;i<L;i++)a[i]=i<l&&i<n?s[i]:0,b[i]=i<k?d[i]:0;for(int i=1;i<L;i++)v[i]=(v[i>>1]>>1)|((i&1)<<(z-1));t(a,L,1);t(b,L,1);for(int i=0;i<L;i++)b[i]=1LL*b[i]*(2-1LL*a[i]*b[i]%P+P)%P;t(b,L,-1);for(int i=k;i<l&&i<n;i++)d[i]=b[i];'
A=A.replace(O,V)
AS=AS.replace(O,V)
AS=AS.replace('for(int i=0;i<=m;i++)g0[i]=g()%P;','f0[n]=o1[n]=g()%(P-1)+1;for(int i=0;i<=m;i++)g0[i]=g()%P;')
X='P4512 【模板】多项式除法'
add('P4512',X,r'''把系数倒序后，多项式最高次项变成常数项。设 $k=n-m+1$，则商的倒序满足

$$Q^R(x)\equiv F^R(x)(G^R(x))^{-1}\pmod{x^k}.$$

用 NTT 和牛顿迭代 $H\leftarrow H(2-G^RH)$ 求逆，再卷积并倒序得到商。最后计算 $R=F-QG$ 的前 $m$ 项。复杂度 $O(n\log n)$，空间复杂度 $O(n)$。''',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},parts=[AB],extra=[('2 1\n1 2 3\n1 1\n','998244352 3\n2\n'),('3 2\n6 8 3 4\n2 0 1\n','3 4\n0 0\n'),('3 2\n5 6 7 8\n0 0 1\n','7 8\n5 6\n'),('4 1\n0 0 0 0 1\n998244352 1\n','1 1 1 1\n1\n')])
en(X,r'Given a polynomial $F(x)$ of degree $n$ and a polynomial $G(x)$ of degree $m$, find polynomials $Q(x)$ and $R(x)$ such that $F(x)=Q(x)G(x)+R(x)$, where $Q$ has degree $n-m$ and $R$ has degree less than $m$. All operations are performed modulo $998244353$.',r'The first line contains $n$ and $m$. The second line contains the $n+1$ coefficients of $F(x)$ in increasing order of degree. The third line contains the $m+1$ coefficients of $G(x)$ in increasing order of degree.',r'Print the $n-m+1$ coefficients of $Q(x)$ on the first line and the $m$ coefficients of $R(x)$ on the second line, both in increasing order of degree. Missing high-degree coefficients of $R$ are printed as zeros.',r'$1\le m<n\le10^5$. Every coefficient is an integer in $[0,998244353)$.')

B=r'''#include <bits/stdc++.h>
using namespace std;const int N=131072,P=998244353;int a[N],b[N],x[N],y[N];void f(int*a,int n,int o,int z){for(int l=1;l<n;l<<=1)for(int i=0;i<n;i+=l<<1)for(int j=0;j<l;j++){int u=a[i+j],v=a[i+j+l];if(o==0){if(z>0)a[i+j+l]=(v+u)%P;else a[i+j+l]=(v-u+P)%P;}else if(o==1){if(z>0)a[i+j]=(u+v)%P;else a[i+j]=(u-v+P)%P;}else if(z>0)a[i+j]=(u+v)%P,a[i+j+l]=(u-v+P)%P;else a[i+j]=1LL*(u+v)*(P+1)/2%P,a[i+j+l]=1LL*(u-v+P)*(P+1)/2%P;}}int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;n=1<<n;for(int i=0;i<n;i++)cin>>a[i];for(int i=0;i<n;i++)cin>>b[i];for(int o=0;o<3;o++){for(int i=0;i<n;i++)x[i]=a[i],y[i]=b[i];f(x,n,o,1);f(y,n,o,1);for(int i=0;i<n;i++)x[i]=1LL*x[i]*y[i]%P;f(x,n,o,-1);for(int i=0;i<n;i++)cout<<x[i]<<' ';cout<<'\n';}}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;const int N=131072,P=998244353;int a[N],b[N],c[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;n=1<<n;for(int i=0;i<n;i++)cin>>a[i];for(int i=0;i<n;i++)cin>>b[i];for(int o=0;o<3;o++){memset(c,0,n*sizeof(int));for(int i=0;i<n;i++)for(int j=0;j<n;j++){int k=o==0?i|j:o==1?i&j:i^j;c[k]=(c[k]+1LL*a[i]*b[j])%P;}for(int i=0;i<n;i++)cout<<c[i]<<' ';cout<<'\n';}}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;const int N=131072,P=998244353;int a[N],b[N];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):17;mt19937_64 g(s);int n=g()%min(17ULL,max(1ULL,z))+1,m=1<<n;cout<<n<<'\n';for(int i=0;i<m;i++)a[i]=g()%P,b[i]=g()%P;for(int i=0;i<m;i++)cout<<a[i]<<' ';cout<<'\n';for(int i=0;i<m;i++)cout<<b[i]<<' ';cout<<'\n';}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;const int N=64,P=998244353;int a[N],b[N],x[N],y[N],o[N];void f(int*a,int n,int q,int z){for(int l=1;l<n;l<<=1)for(int i=0;i<n;i+=l<<1)for(int j=0;j<l;j++){int u=a[i+j],v=a[i+j+l];if(q==0){if(z>0)a[i+j+l]=(v+u)%P;else a[i+j+l]=(v-u+P)%P;}else if(q==1){if(z>0)a[i+j]=(u+v)%P;else a[i+j]=(u-v+P)%P;}else if(z>0)a[i+j]=(u+v)%P,a[i+j+l]=(u-v+P)%P;else a[i+j]=1LL*(u+v)*(P+1)/2%P,a[i+j+l]=1LL*(u-v+P)*(P+1)/2%P;}}int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=1<<(g()%6+1);for(int i=0;i<n;i++)a[i]=g()%P,b[i]=g()%P;for(int q=0;q<3;q++){memset(o,0,sizeof o);for(int i=0;i<n;i++)x[i]=a[i],y[i]=b[i];for(int i=0;i<n;i++)for(int j=0;j<n;j++){int k=q==0?i|j:q==1?i&j:i^j;o[k]=(o[k]+1LL*a[i]*b[j])%P;}f(x,n,q,1);f(y,n,q,1);for(int i=0;i<n;i++)x[i]=1LL*x[i]*y[i]%P;f(x,n,q,-1);for(int i=0;i<n;i++)if(x[i]!=o[i])return cout<<"WA\n",1;}}cout<<"OK\n";}
'''
Y='P4717 【模板】快速莫比乌斯 _ 沃尔什变换 (FMT _ FWT)'
add('P4717',Y,r'''OR 卷积按位做子集和变换，上半块加下半块；AND 卷积对称地让下半块加上半块。两者的逆变换把对应加法改为减法。

XOR 卷积每个蝴蝶把 $(u,v)$ 变成 $(u+v,u-v)$，逆变换再同时除以二。两个序列正变换后逐点相乘，再逆变换即可。

三种变换均有 $n$ 层，每层访问 $2^n$ 个元素，复杂度 $O(n2^n)$，空间复杂度 $O(2^n)$。''',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},parts=[BB],extra=[('1\n1 0\n0 1\n','0 1\n1 0\n0 1\n'),('2\n5 0 0 0\n1 2 3 4\n','5 10 15 20\n50 0 0 0\n5 10 15 20\n'),('2\n1 1 1 1\n1 1 1 1\n','1 3 3 9\n9 3 3 1\n4 4 4 4\n'),('1\n998244352 1\n1 1\n','998244352 1\n998244352 1\n0 0\n')])
en(Y,r'Given two sequences $A$ and $B$ of length $2^n$, define $C_i=\sum_{j\mathbin{\circ}k=i}A_jB_k$. Compute $C$ when $\circ$ is bitwise OR, bitwise AND, and bitwise XOR.',r'The first line contains $n$. The second line contains $2^n$ integers $A_0,\ldots,A_{2^n-1}$, and the third line contains $2^n$ integers $B_0,\ldots,B_{2^n-1}$.',r'Print three lines of $2^n$ integers. They are the OR, AND, and XOR convolutions, respectively, modulo $998244353$.',r'$1\le n\le17$ and $0\le A_i,B_i<998244353$.')

C=r'''#include <bits/stdc++.h>
using namespace std;const int N=2005,P=998244353;int x[N],y[N];int q(int a,int n=P-2){int r=1;for(;n;n>>=1,a=1LL*a*a%P)if(n&1)r=1LL*r*a%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n,k;cin>>n>>k;for(int i=0;i<n;i++){cin>>x[i]>>y[i];if(x[i]==k){cout<<y[i]<<'\n';return 0;}}long long r=0;for(int i=0;i<n;i++){long long a=1,b=1;for(int j=0;j<n;j++)if(i!=j)a=a*(k-x[j]+P)%P,b=b*(x[i]-x[j]+P)%P;r=(r+y[i]*a%P*q(b))%P;}cout<<r<<'\n';}
'''
CB=r'''#include <bits/stdc++.h>
using namespace std;const int N=2005,P=998244353;int x[N],y[N],a[N],b[N],c[N];int q(int a,int n=P-2){int r=1;for(;n;n>>=1,a=1LL*a*a%P)if(n&1)r=1LL*r*a%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n,k;cin>>n>>k;for(int i=0;i<n;i++)cin>>x[i]>>y[i];for(int i=0;i<n;i++){memset(a,0,(n+1)*sizeof(int));a[0]=1;int d=0;long long z=1;for(int j=0;j<n;j++)if(i!=j){memset(b,0,(n+1)*sizeof(int));for(int l=0;l<=d;l++)b[l]=(b[l]-1LL*a[l]*x[j]%P+P)%P,b[l+1]=(b[l+1]+a[l])%P;memcpy(a,b,(n+1)*sizeof(int));d++;z=z*(x[i]-x[j]+P)%P;}z=y[i]*q(z)%P;for(int j=0;j<n;j++)c[j]=(c[j]+z*a[j])%P;}long long r=0;for(int i=n-1;i>=0;i--)r=(r*k+c[i])%P;cout<<r<<'\n';}
'''
CB=CB.replace('z=y[i]*q(z)%P;','z=1LL*y[i]*q(z)%P;')
CG=r'''#include <bits/stdc++.h>
using namespace std;const int N=2005,P=998244353;int x[N],y[N];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):2000;mt19937_64 g(s);int n=g()%min(2000ULL,max(1ULL,z))+1,k=g()%(P-1)+1;for(int i=0;i<n;i++)x[i]=i+1,y[i]=g()%(P-1)+1;for(int i=n-1;i;i--){int j=g()%(i+1);swap(x[i],x[j]);swap(y[i],y[j]);}cout<<n<<' '<<k<<'\n';for(int i=0;i<n;i++)cout<<x[i]<<' '<<y[i]<<'\n';}
'''
CS=r'''#include <bits/stdc++.h>
using namespace std;const int N=12,P=998244353;int x[N],y[N],a[N],b[N],c0[N];int q(int a,int n=P-2){int r=1;for(;n;n>>=1,a=1LL*a*a%P)if(n&1)r=1LL*r*a%P;return r;}int f(int n,int k){for(int i=0;i<n;i++)if(x[i]==k)return y[i];long long r=0;for(int i=0;i<n;i++){long long a0=1,b0=1;for(int j=0;j<n;j++)if(i!=j)a0=a0*(k-x[j]+P)%P,b0=b0*(x[i]-x[j]+P)%P;r=(r+y[i]*a0%P*q(b0))%P;}return r;}int h(int n,int k){memset(c0,0,sizeof c0);for(int i=0;i<n;i++){memset(a,0,sizeof a);a[0]=1;int d=0;long long z=1;for(int j=0;j<n;j++)if(i!=j){memset(b,0,sizeof b);for(int l=0;l<=d;l++)b[l]=(b[l]-1LL*a[l]*x[j]%P+P)%P,b[l+1]=(b[l+1]+a[l])%P;memcpy(a,b,sizeof a);d++;z=z*(x[i]-x[j]+P)%P;}z=y[i]*q(z)%P;for(int j=0;j<n;j++)c0[j]=(c0[j]+z*a[j])%P;}long long r=0;for(int i=n-1;i>=0;i--)r=(r*k+c0[i])%P;return r;}int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%8+1,k=g()%20+1;for(int i=0;i<n;i++)x[i]=i+1,y[i]=g()%P;for(int i=n-1;i;i--){int j=g()%(i+1);swap(x[i],x[j]);swap(y[i],y[j]);}if(f(n,k)!=h(n,k))return cout<<"WA\n",1;}cout<<"OK\n";}
'''
CS=CS.replace('z=y[i]*q(z)%P;','z=1LL*y[i]*q(z)%P;')
Z='P4781 【模板】拉格朗日插值'
add('P4781',Z,r'''拉格朗日基函数在 $x_i$ 处为一、在其余给定横坐标处为零，因此

$$f(k)=\sum_{i=1}^n y_i\prod_{j\ne i}\frac{k-x_j}{x_i-x_j}\pmod{998244353}.$$

逐项计算分子与分母，分母用费马小定理求逆。若 $k$ 等于某个 $x_i$，可直接输出 $y_i$。复杂度 $O(n^2+n\log P)$，空间复杂度 $O(n)$。''',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},parts=[CB],extra=[('1 123\n7 42\n','42\n'),('2 3\n1 5\n2 8\n','11\n'),('4 123\n1 9\n5 9\n10 9\n20 9\n','9\n')])
en(Z,r'For $n$ points $(x_i,y_i)$ with pairwise distinct $x_i$, there is a unique polynomial $f$ of degree at most $n-1$ passing through all points. Find $f(k)$ modulo $998244353$.',r'The first line contains $n$ and $k$. Each of the next $n$ lines contains one pair $x_i,y_i$.',r'Print the value of $f(k)$ modulo $998244353$.',r'$1\le n\le2000$, $1\le x_i,y_i,k<998244353$, and all $x_i$ are distinct.')
