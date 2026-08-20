from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const long long P=999911659,M=999911658,Q[4]={2,3,4679,35617};long long f[40005],d[100005];long long pw(long long a,long long b,long long p){long long r=1;for(;b;b>>=1,a=a*a%p)if(b&1)r=r*a%p;return r;}long long c(long long n,long long m,long long p){if(m>n)return 0;return f[n]*pw(f[m]*f[n-m]%p,p-2,p)%p;}long long l(long long n,long long m,long long p){long long r=1;while(n||m){r=r*c(n%p,m%p,p)%p;n/=p;m/=p;}return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);long long n,g;cin>>n>>g;if(g%P==0)return cout<<0<<'\n',0;int z=0;for(long long i=1;i*i<=n;i++)if(n%i==0){d[z++]=i;if(i*i<n)d[z++]=n/i;}long long x=0;for(int k=0;k<4;k++){long long p=Q[k],s=0;f[0]=1;for(int i=1;i<p;i++)f[i]=f[i-1]*i%p;for(int i=0;i<z;i++)s=(s+l(n,d[i],p))%p;long long m=M/p;x=(x+s*m%M*pw(m%p,p-2,p))%M;}cout<<pw(g,x,P)<<'\n';}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;const long long P=999911659,M=999911658;long long c[1005][1005];long long pw(long long a,long long b){long long r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long g,s=0;cin>>n>>g;c[0][0]=1;for(int i=1;i<=n;i++){c[i][0]=1;for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;}for(int i=1;i<=n;i++)if(n%i==0)s=(s+c[n][i])%M;cout<<(g%P?pw(g,s):0)<<'\n';}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):1000000000;mt19937_64 g(s);cout<<g()%min(1000000000ULL,max(1ULL,z))+1<<' '<<g()%1000000000+1<<'\n';}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;const long long P=999911659,M=999911658,Q[4]={2,3,4679,35617};long long f[40005],d[1005],c[105][105];long long pw(long long a,long long b,long long p){long long r=1;for(;b;b>>=1,a=a*a%p)if(b&1)r=r*a%p;return r;}long long C(long long n,long long m,long long p){if(m>n)return 0;return f[n]*pw(f[m]*f[n-m]%p,p-2,p)%p;}long long L(long long n,long long m,long long p){long long r=1;while(n||m){r=r*C(n%p,m%p,p)%p;n/=p;m/=p;}return r;}int main(int V,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=V>1?stoi(v[1]):1000;unsigned long long e=V>2?stoull(v[2]):1;mt199_64:;mt19937_64 g(e);while(R--){int n=g()%80+1,z=0;long long a=g()%1000000000+1,x=0,y=0;c[0][0]=1;for(int i=1;i<=n;i++){c[i][0]=1;for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;}for(int i=1;i<=n;i++)if(n%i==0)d[z++]=i,y=(y+c[n][i])%M;for(int k=0;k<4;k++){long long p=Q[k],s=0,m=M/p;f[0]=1;for(int i=1;i<p;i++)f[i]=f[i-1]*i%p;for(int i=0;i<z;i++)s=(s+L(n,d[i],p))%p;x=(x+s*m%M*pw(m%p,p-2,p))%M;}if(pw(a,x,P)!=pw(a,y,P))return cout<<"WA\n",1;}cout<<"OK\n";}
'''.replace('mt199_64:;','')
add('P2480','P2480 [SDOI2010] 古代猪文',r'''设指数为 $S=\sum_{d\mid n}\binom nd$。模数 $P=999911659$ 是质数，因此指数只需模 $P-1=2\times3\times4679\times35617$。

对这四个质数分别用 Lucas 定理求每个组合数，枚举 $n$ 的约数累加，再用 CRT 合并出 $S\bmod(P-1)$，最后快速幂。若 $g\equiv0\pmod P$，由于 $S>0$，答案直接为零。''',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},parts=[AB],extra=[('1 7\n','7\n'),('2 3\n','27\n'),('3 2\n','16\n'),('999911659 999911659\n','0\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;using u=unsigned long long;using U=__uint128_t;u p(u a,u b,u m){u r=1;for(;b;b>>=1,a=(U)a*a%m)if(b&1)r=(U)r*a%m;return r;}bool q(u n){if(n<2)return 0;for(u x:{2,3,5,7,11,13,17,19,23,29,31,37}){if(n%x==0)return n==x;}u d=n-1,s=0;while(!(d&1))d>>=1,s++;for(u a:{2,325,9375,28178,450775,9780504,1795265022})if(a%n){u x=p(a%n,d,n);if(x==1||x==n-1)continue;bool f=0;for(u i=1;i<s;i++)if((x=(U)x*x%n)==n-1){f=1;break;}if(!f)return 0;}return 1;}u g(u n){if(!(n&1))return 2;static mt19937_64 r(1);for(;;){u c=r()%(n-1)+1,x=r()%n,y=x,d=1;auto f=[&](u x){return ((U)x*x+c)%n;};while(d==1){x=f(x);y=f(f(y));d=__gcd(x>y?x-y:y-x,n);}if(d<n)return d;}}u a(u n){if(q(n))return n;u d=g(n);return max(a(d),a(n/d));}int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){u n;cin>>n;if(q(n))cout<<"Prime\n";else cout<<a(n)<<'\n';}}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){unsigned long long n,m,x=0;cin>>n;m=n;for(unsigned long long i=2;i*i<=m;i++)while(m%i==0)x=i,m/=i;if(m<n&&m>1)x=m;if(!x)cout<<"Prime\n";else cout<<x<<'\n';}}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):1000000000000000000ULL;mt19937_64 g(s);int T=min(350ULL,max(1ULL,z/10000000000000000ULL+1));cout<<T<<'\n';while(T--)cout<<g()%(min(1000000000000000000ULL,max(2ULL,z))-1)+2<<'\n';}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;using u=unsigned long long;using U=__uint128_t;u p(u a,u b,u m){u r=1;for(;b;b>>=1,a=(U)a*a%m)if(b&1)r=(U)r*a%m;return r;}bool q(u n){if(n<2)return 0;for(u x:{2,3,5,7,11,13,17,19,23,29,31,37}){if(n%x==0)return n==x;}u d=n-1,s=0;while(!(d&1))d>>=1,s++;for(u a:{2,325,9375,28178,450775,9780504,1795265022})if(a%n){u x=p(a%n,d,n);if(x==1||x==n-1)continue;bool f=0;for(u i=1;i<s;i++)if((x=(U)x*x%n)==n-1){f=1;break;}if(!f)return 0;}return 1;}u g(u n){if(!(n&1))return 2;static mt19937_64 r(1);for(;;){u c=r()%(n-1)+1,x=r()%n,y=x,d=1;auto f=[&](u x){return ((U)x*x+c)%n;};while(d==1){x=f(x);y=f(f(y));d=__gcd(x>y?x-y:y-x,n);}if(d<n)return d;}}u a(u n){if(q(n))return n;u d=g(n);return max(a(d),a(n/d));}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;u s=C>2?stoull(v[2]):1;mt19937_64 r(s);while(R--){u n=r()%100000000+2,x=n,y=0;for(u i=2;i*i<=x;i++)while(x%i==0)y=i,x/=i;if(x<n&&x>1)y=x;if((q(n)?0:a(n))!=y)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P4718','P4718 【模板】Pollard-Rho',r'''先用确定性 Miller–Rabin 判断 $64$ 位整数是否为质数。取适用于 $2^{64}$ 范围的一组固定底数，并用 `__int128` 完成安全乘法。

对合数使用 Pollard-Rho 找到一个非平凡因子，递归分解两部分并取最大质因子。算法为随机期望复杂度。''',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},extra=[('4\n4\n97\n9999999967\n1000000016000000063\n','2\nPrime\nPrime\n1000000009\n'),('3\n6\n49\n999999996989\n','3\n7\n383609\n'),('3\n100\n600851475143\n999985999949\n','5\n6857\n1000003\n')])

C=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=2;;i++)if(n%i==0)return cout<<n/i<<'\n',0;}
'''
CB=C
CG=r'''#include <bits/stdc++.h>
using namespace std;const int N=78498;int p[N],v[1000005];int main(int c,char**x){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(x[1]):1,z=c>2?stoull(x[2]):1000000;mt19937_64 g(s);int k=0;for(int i=2;i<=1000000;i++){if(!v[i])p[k++]=i;for(int j=0;j<k&&1LL*i*p[j]<=1000000;j++){v[i*p[j]]=1;if(i%p[j]==0)break;}}unsigned long long m=min(2000000000ULL,max(6ULL,z));int t=upper_bound(p,p+k,(int)sqrt(m))-p,a=p[g()%t],u=upper_bound(p,p+k,(int)min(1000000ULL,m/a))-p,b=p[g()%u];while(a==b)b=p[g()%u];cout<<1LL*a*b<<'\n';}
'''
CS=r'''#include <bits/stdc++.h>
using namespace std;const int N=10000;int p[N],v[100005];int main(int C,char**x){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(x[1]):1000;unsigned long long s=C>2?stoull(x[2]):1;mt19937_64 g(s);int k=0;for(int i=2;i<=100000;i++){if(!v[i])p[k++]=i;for(int j=0;j<k&&1LL*i*p[j]<=100000;j++){v[i*p[j]]=1;if(i%p[j]==0)break;}}while(R--){int a=p[g()%k],b=p[g()%k];if(a==b){R++;continue;}long long n=1LL*a*b,r=0;for(int i=2;i*i<=n;i++)if(n%i==0){r=n/i;break;}if(r!=max(a,b))return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P1075','P1075 [NOIP 2012 普及组] 质因数分解',r'''从 $2$ 开始寻找 $n$ 的最小因子 $p$。题目保证 $n$ 是两个不同质数的乘积，因此第一次整除时，另一个质数 $n/p$ 一定更大，直接输出即可。复杂度 $O(\sqrt n)$。''',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},extra=[('6\n','3\n'),('35\n','7\n'),('199982\n','99991\n')])

D=r'''#include <bits/stdc++.h>
using namespace std;const int N=40005;int p[N],v[N],f[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,k=0;long long r=3;cin>>n;if(n==1)return cout<<0<<'\n',0;f[1]=1;for(int i=2;i<n;i++){if(!v[i])p[k++]=i,f[i]=i-1;for(int j=0;j<k&&i*p[j]<n;j++){v[i*p[j]]=1;if(i%p[j]==0){f[i*p[j]]=f[i]*p[j];break;}f[i*p[j]]=f[i]*(p[j]-1);}}for(int i=2;i<n;i++)r+=2*f[i];cout<<r<<'\n';}
'''
DB=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int n,r=0;cin>>n;for(int i=0;i<n;i++)for(int j=0;j<n;j++)if((i||j)&&__gcd(i,j)==1)r++;cout<<r<<'\n';}
'''
DG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):40000;mt19937_64 g(s);cout<<g()%min(40000ULL,max(1ULL,z))+1<<'\n';}
'''
DS=r'''#include <bits/stdc++.h>
using namespace std;int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%100+1;long long a=n==1?0:3,b=0;for(int i=2;i<n;i++){int x=i,r=i;for(int p=2;p*p<=x;p++)if(x%p==0){r=r/p*(p-1);while(x%p==0)x/=p;}if(x>1)r=r/x*(x-1);a+=2*r;}for(int i=0;i<n;i++)for(int j=0;j<n;j++)if((i||j)&&__gcd(i,j)==1)b++;if(a!=b)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P2158','P2158 [SDOI2008] 仪仗队',r'''除去最近的三个位置，第一象限中斜率不同的可见点对应互质坐标。固定横坐标 $i$ 时共有 $\varphi(i)$ 个新的方向，关于对角线对称，所以

$$\text{ans}=3+2\sum_{i=2}^{N-1}\varphi(i).$$

$N=1$ 单独输出零。用线性筛求欧拉函数，总复杂度 $O(N)$。''',{'.cpp':D,' 数据生成.cpp':DG,' 暴力.cpp':DB,' 对拍.cpp':DS},extra=[('1\n','0\n'),('2\n','3\n'),('3\n','5\n'),('5\n','13\n')])
