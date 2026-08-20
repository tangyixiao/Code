from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=10000005;int p[N],v[N],f[N];long long s[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,k=0;long long r=0;cin>>n;f[1]=1;for(int i=2;i<=n;i++){if(!v[i])p[k++]=i,f[i]=i-1;for(int j=0;j<k&&1LL*i*p[j]<=n;j++){v[i*p[j]]=1;if(i%p[j]==0){f[i*p[j]]=f[i]*p[j];break;}f[i*p[j]]=f[i]*(p[j]-1);}}for(int i=1;i<=n;i++)s[i]=s[i-1]+f[i];for(int i=0;i<k;i++)r+=2*s[n/p[i]]-1;cout<<r<<'\n';}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;bool p(int x){if(x<2)return 0;for(int i=2;i*i<=x;i++)if(x%i==0)return 0;return 1;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n,r=0;cin>>n;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)r+=p(__gcd(i,j));cout<<r<<'\n';}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):10000000;mt19937_64 g(s);cout<<g()%min(10000000ULL,max(1ULL,z))+1<<'\n';}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;const int N=105;int p[N],v[N],f[N],s[N];bool q(int x){if(x<2)return 0;for(int i=2;i*i<=x;i++)if(x%i==0)return 0;return 1;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long z=C>2?stoull(v[2]):1;mt19937_64 g(z);while(R--){int n=g()%100+1,k=0,a=0,b=0;memset(v,0,sizeof v);f[1]=1;for(int i=2;i<=n;i++){if(!v[i])p[k++]=i,f[i]=i-1;for(int j=0;j<k&&i*p[j]<=n;j++){v[i*p[j]]=1;if(i%p[j]==0){f[i*p[j]]=f[i]*p[j];break;}f[i*p[j]]=f[i]*(p[j]-1);}}for(int i=1;i<=n;i++)s[i]=s[i-1]+f[i];for(int i=0;i<k;i++)a+=2*s[n/p[i]]-1;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)b+=q(__gcd(i,j));if(a!=b)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
AS=AS.replace('char**v','char**V').replace('stoi(v[1])','stoi(V[1])').replace('stoull(v[2])','stoull(V[2])')
add('P2568','P2568 GCD',r'''固定质数 $p=\gcd(x,y)$，令 $x=pa,y=pb$，则 $1\le a,b\le\lfloor n/p\rfloor$ 且互质。边长为 $m$ 的正整数方阵中有序互质对数量为

$$2\sum_{i=1}^{m}\varphi(i)-1.$$

线性筛出质数与欧拉函数前缀和，对每个不超过 $n$ 的质数累加该式，复杂度 $O(n)$。''',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},extra=[('1\n','0\n'),('2\n','1\n'),('3\n','2\n'),('5\n','5\n'),('10\n','30\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;const int N=100005;int p[N],v[N];long long f[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,k=0;long long r=0;cin>>n;f[1]=1;for(int i=2;i<=n;i++){if(!v[i])p[k++]=i,f[i]=i-1;for(int j=0;j<k&&i*p[j]<=n;j++){v[i*p[j]]=1;if(i%p[j]==0){f[i*p[j]]=f[i]*p[j];break;}f[i*p[j]]=f[i]*(p[j]-1);}}for(int i=1;i<=n;i++)r+=f[i]*(n/i)*(n/i);cout<<r<<'\n';}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long r=0;cin>>n;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)r+=__gcd(i,j);cout<<r<<'\n';}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100000;mt19937_64 g(s);cout<<g()%min(100000ULL,max(1ULL,z))+1<<'\n';}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;const int N=105;int p[N],v[N];long long f[N];int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long z=C>2?stoull(v[2]):1;mt19937_64 g(z);while(R--){int n=g()%100+1,k=0;long long a=0,b=0;memset(v,0,sizeof v);f[1]=1;for(int i=2;i<=n;i++){if(!v[i])p[k++]=i,f[i]=i-1;for(int j=0;j<k&&i*p[j]<=n;j++){v[i*p[j]]=1;if(i%p[j]==0){f[i*p[j]]=f[i]*p[j];break;}f[i*p[j]]=f[i]*(p[j]-1);}}for(int i=1;i<=n;i++)a+=f[i]*(n/i)*(n/i);for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)b+=__gcd(i,j);if(a!=b)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
BS=BS.replace('char**v','char**V').replace('stoi(v[1])','stoi(V[1])').replace('stoull(v[2])','stoull(V[2])')
add('P2398','P2398 GCD SUM',r'''利用恒等式 $x=\sum_{d\mid x}\varphi(d)$，交换求和顺序：

$$\sum_{i=1}^n\sum_{j=1}^n\gcd(i,j)=\sum_{d=1}^n\varphi(d)\left\lfloor\frac nd\right\rfloor^2.$$

线性筛求出所有欧拉函数后直接累加，复杂度 $O(n)$。''',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},parts=[BB],extra=[('1\n','1\n'),('3\n','12\n'),('4\n','24\n'),('10\n','189\n')])

C=r'''#include <bits/stdc++.h>
using namespace std;const int N=10000005;int p[N],v[N],f[N];long long q(long long a,long long b,int m){long long r=1;for(;b;b>>=1,a=a*a%m)if(b&1)r=r*a%m;return r;}int s(int x){return x==1?0:q(2,s(f[x])+f[x],x);}int main(){ios::sync_with_stdio(0);cin.tie(0);int T,n=10000000,k=0;f[1]=1;for(int i=2;i<=n;i++){if(!v[i])p[k++]=i,f[i]=i-1;for(int j=0;j<k&&1LL*i*p[j]<=n;j++){v[i*p[j]]=1;if(i%p[j]==0){f[i*p[j]]=f[i]*p[j];break;}f[i*p[j]]=f[i]*(p[j]-1);}}cin>>T;while(T--){int x;cin>>x;cout<<s(x)<<'\n';}}
'''
CB=r'''#include <bits/stdc++.h>
using namespace std;int f(int n){int r=n,x=n;for(int p=2;p*p<=x;p++)if(x%p==0){r=r/p*(p-1);while(x%p==0)x/=p;}if(x>1)r=r/x*(x-1);return r;}long long q(long long a,long long b,int m){long long r=1;for(;b;b>>=1,a=a*a%m)if(b&1)r=r*a%m;return r;}int s(int x){return x==1?0:q(2,s(f(x))+f(x),x);}int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){int p;cin>>p;cout<<s(p)<<'\n';}}
'''
CG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):10000000;mt19937_64 g(s);int T=min(1000ULL,max(1ULL,z/10000+1));cout<<T<<'\n';while(T--)cout<<g()%min(10000000ULL,max(1ULL,z))+1<<'\n';}
'''
CS=r'''#include <bits/stdc++.h>
using namespace std;const int N=1005;int p[N],v[N],f[N];long long q(long long a,long long b,int m){long long r=1;for(;b;b>>=1,a=a*a%m)if(b&1)r=r*a%m;return r;}int s(int x){return x==1?0:q(2,s(f[x])+f[x],x);}int F(int n){int r=n,x=n;for(int p=2;p*p<=x;p++)if(x%p==0){r=r/p*(p-1);while(x%p==0)x/=p;}if(x>1)r=r/x*(x-1);return r;}int S(int x){return x==1?0:q(2,S(F(x))+F(x),x);}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long z=C>2?stoull(v[2]):1;mt19937_64 g(z);int k=0;f[1]=1;for(int i=2;i<=1000;i++){if(!v[i])p[k++]=i,f[i]=i-1;for(int j=0;j<k&&i*p[j]<=1000;j++){v[i*p[j]]=1;if(i%p[j]==0){f[i*p[j]]=f[i]*p[j];break;}f[i*p[j]]=f[i]*(p[j]-1);}}while(R--){int x=g()%1000+1;if(s(x)!=S(x))return cout<<"WA\n",1;}cout<<"OK\n";}
'''
CS=CS.replace('char**v','char**V').replace('stoi(v[1])','stoi(V[1])').replace('stoull(v[2])','stoull(V[2])')
add('P4139','P4139 上帝与集合的正确用法',r'''设稳定值为 $F(p)$。指数塔足够高，因此即使底数与模数不互质，也可在指数对 $\varphi(p)$ 取模后补上一个 $\varphi(p)$：

$$F(p)=2^{F(\varphi(p))+\varphi(p)}\bmod p,\qquad F(1)=0.$$

先线性筛出 $10^7$ 以内的欧拉函数，每次询问沿欧拉函数链递归，链长很短。''',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},extra=[('5\n1\n4\n5\n7\n10\n','0\n0\n1\n2\n6\n'),('3\n8\n9\n12\n','0\n7\n4\n'),('3\n16\n25\n100\n','0\n11\n36\n')])

D=r'''#include <bits/stdc++.h>
using namespace std;const int N=1000005;const long long P=104857601;int p[N],v[N];long long q(long long a,long long b){long long r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n,k=0;long long r=1;cin>>n;for(int i=2;i<=n;i++){if(!v[i])p[k++]=i;for(int j=0;j<k&&i*p[j]<=n;j++){v[i*p[j]]=1;if(i%p[j]==0)break;}}for(int i=0;i<k;i++){long long e=0;for(long long x=p[i],y=n/x;y;x*=p[i],y=n/x)e+=2*y*(n-y);r=r*q(p[i],e)%P;}cout<<r<<'\n';}
'''
DB=r'''#include <bits/stdc++.h>
using namespace std;const long long P=104857601;int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long r=1;cin>>n;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){long long g=__gcd(i,j);r=r*(1LL*i/g*j/g)%P;}cout<<r<<'\n';}
'''
DG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):1000000;mt19937_64 g(s);cout<<g()%min(1000000ULL,max(1ULL,z))+1<<'\n';}
'''
DS=r'''#include <bits/stdc++.h>
using namespace std;const int N=105;const long long P=104857601;int p[N],v[N];long long q(long long a,long long b){long long r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long z=C>2?stoull(v[2]):1;mt19937_64 g(z);while(R--){int n=g()%100+1,k=0;long long a=1,b=1;memset(v,0,sizeof v);for(int i=2;i<=n;i++){if(!v[i])p[k++]=i;for(int j=0;j<k&&i*p[j]<=n;j++){v[i*p[j]]=1;if(i%p[j]==0)break;}}for(int i=0;i<k;i++){long long e=0;for(long long x=p[i],y=n/x;y;x*=p[i],y=n/x)e+=2*y*(n-y);a=a*q(p[i],e)%P;}for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){long long d=__gcd(i,j);b=b*(1LL*i/d*j/d)%P;}if(a!=b)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
DS=DS.replace('char**v','char**V').replace('stoi(v[1])','stoi(V[1])').replace('stoull(v[2])','stoull(V[2])')
add('P5221','P5221 Product',r'''有 $\operatorname{lcm}(i,j)/\gcd(i,j)=ij/\gcd(i,j)^2$。分质数统计指数。对质数 $p$ 的每个幂 $p^k$，令 $q=\lfloor N/p^k\rfloor$：分子贡献指数 $2Nq$，所有 gcd 的平方贡献 $2q^2$，净贡献为 $2q(N-q)$。

筛出所有质数，枚举其幂并快速幂累乘即可，复杂度 $O(N\log\log N)$。''',{'.cpp':D,' 数据生成.cpp':DG,' 暴力.cpp':DB,' 对拍.cpp':DS},parts=[DB],extra=[('1\n','1\n'),('2\n','4\n'),('3\n','1296\n'),('10\n','5718072\n')])
