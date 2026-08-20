from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=10000005,P=20101009;int p[N],f[N];bool v[N];long long s(long long n){return n%P*((n+1)%P)%P*((P+1)/2)%P;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m,z=0;cin>>n>>m;if(n>m)swap(n,m);f[1]=1;for(int i=2;i<=n;i++){if(!v[i])p[z++]=i,f[i]=1LL*i*(1-i)%P;for(int j=0;j<z&&1LL*i*p[j]<=n;j++){int x=i*p[j];v[x]=1;if(i%p[j]==0){f[x]=1LL*f[i]*p[j]%P;break;}f[x]=1LL*f[i]*p[j]%P*(1-p[j])%P;}}for(int i=1;i<=n;i++)f[i]=(f[i]+f[i-1])%P;long long r=0;for(int l=1,q;l<=n;l=q+1){q=min(n/(n/l),m/(m/l));r=(r+1LL*(f[q]-f[l-1])*s(n/l)%P*s(m/l))%P;}cout<<(r+P)%P<<'\n';}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;const int P=20101009;int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;long long r=0;cin>>n>>m;for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)r=(r+1LL*i/__gcd(i,j)*j)%P;cout<<r<<'\n';}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):10000000;mt19937_64 g(s);z=min(10000000ULL,max(1ULL,z));cout<<g()%z+1<<' '<<g()%z+1<<'\n';}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;const int N=105,P=20101009;int p[N],f[N];bool v[N];long long s(long long n){return n*(n+1)/2%P;}int main(int C,char**V){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(V[1]):1000;unsigned long long z=C>2?stoull(V[2]):1;mt19937_64 g(z);while(R--){int n=g()%100+1,m=g()%100+1,k=0;long long a=0,b=0;memset(v,0,sizeof v);memset(f,0,sizeof f);f[1]=1;for(int i=2;i<=min(n,m);i++){if(!v[i])p[k++]=i,f[i]=1LL*i*(1-i)%P;for(int j=0;j<k&&i*p[j]<=min(n,m);j++){int x=i*p[j];v[x]=1;if(i%p[j]==0){f[x]=1LL*f[i]*p[j]%P;break;}f[x]=1LL*f[i]*p[j]%P*(1-p[j])%P;}}for(int i=1;i<=min(n,m);i++)f[i]=(f[i]+f[i-1])%P;for(int l=1,q;l<=min(n,m);l=q+1){q=min(n/(n/l),m/(m/l));a=(a+1LL*(f[q]-f[l-1])*s(n/l)%P*s(m/l))%P;}for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)b=(b+1LL*i/__gcd(i,j)*j)%P;if((a+P)%P!=b)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P1829','P1829 [集训队互测 2010] Crash的数字表格 _ JZPTAB',r'''令 $i=da,j=db$ 且 $\gcd(a,b)=1$，再对互质条件做莫比乌斯反演并合并 $d$ 与反演变量。最终得到

$$\sum_{k=1}^{\min(n,m)}F(k)S(\lfloor n/k\rfloor)S(\lfloor m/k\rfloor),$$

其中 $S(x)=x(x+1)/2$，$F(k)=k\prod_{p\mid k}(1-p)$。用线性筛求 $F$ 的前缀和，再整除分块，复杂度 $O(n)$。''',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},parts=[AB],extra=[('1 1\n','1\n'),('2 3\n','16\n'),('3 3\n','28\n'),('10 10\n','2127\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;const int N=1000005;const long long P=1000000007;int p[N],v[N],u[N];long long f[N],o[N],a[N],b[N];long long q(long long x,long long y){long long r=1;for(;y;y>>=1,x=x*x%P)if(y&1)r=r*x%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int z=0;u[1]=1;for(int i=2;i<N;i++){if(!v[i])p[z++]=i,u[i]=-1;for(int j=0;j<z&&i*p[j]<N;j++){v[i*p[j]]=1;if(i%p[j]==0){u[i*p[j]]=0;break;}u[i*p[j]]=-u[i];}}f[1]=1;for(int i=2;i<N;i++)f[i]=(f[i-1]+f[i-2])%P;a[0]=1;for(int i=1;i<N;i++)a[i]=a[i-1]*f[i]%P;long long x=q(a[N-1],P-2);for(int i=N-1;i;i--)o[i]=x*a[i-1]%P,x=x*f[i]%P;for(int i=0;i<N;i++)a[i]=b[i]=1;for(int d=1;d<N;d++)for(int k=1;d*k<N;k++)if(u[k]>0)a[d*k]=a[d*k]*f[d]%P,b[d*k]=b[d*k]*o[d]%P;else if(u[k]<0)a[d*k]=a[d*k]*o[d]%P,b[d*k]=b[d*k]*f[d]%P;for(int i=1;i<N;i++)a[i]=a[i]*a[i-1]%P,b[i]=b[i]*b[i-1]%P;int T;cin>>T;while(T--){int n,m;cin>>n>>m;if(n>m)swap(n,m);long long r=1;for(int l=1,d;l<=n;l=d+1){d=min(n/(n/l),m/(m/l));long long w=a[d]*b[l-1]%P,e=1LL*(n/l)*(m/l);r=r*q(w,e)%P;}cout<<r<<'\n';}}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;const long long P=1000000007;long long f[105];int main(){ios::sync_with_stdio(0);cin.tie(0);f[1]=1;for(int i=2;i<105;i++)f[i]=(f[i-1]+f[i-2])%P;int T;cin>>T;while(T--){int n,m;long long r=1;cin>>n>>m;for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)r=r*f[__gcd(i,j)]%P;cout<<r<<'\n';}}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int T=g()%min(1000ULL,max(1ULL,z))+1;cout<<T<<'\n';while(T--)cout<<g()%1000000+1<<' '<<g()%1000000+1<<'\n';}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;const int N=105;const long long P=1000000007;int u[N];long long f[N],o[N],a[N],b[N];long long q(long long x,long long y){long long r=1;for(;y;y>>=1,x=x*x%P)if(y&1)r=r*x%P;return r;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long z=C>2?stoull(v[2]):1;mt19937_64 g(z);u[1]=1;for(int i=1;i<100;i++)for(int j=i+i;j<100;j+=i)u[j]-=u[i];f[1]=1;for(int i=2;i<100;i++)f[i]=(f[i-1]+f[i-2])%P;for(int i=1;i<100;i++)o[i]=q(f[i],P-2),a[i]=b[i]=1;a[0]=b[0]=1;for(int d=1;d<100;d++)for(int k=1;d*k<100;k++)if(u[k]>0)a[d*k]=a[d*k]*f[d]%P,b[d*k]=b[d*k]*o[d]%P;else if(u[k]<0)a[d*k]=a[d*k]*o[d]%P,b[d*k]=b[d*k]*f[d]%P;for(int i=1;i<100;i++)a[i]=a[i]*a[i-1]%P,b[i]=b[i]*b[i-1]%P;while(R--){int n=g()%50+1,m=g()%50+1;long long A=1,B=1;for(int l=1,d;l<=min(n,m);l=d+1){d=min(n/(n/l),m/(m/l));A=A*q(a[d]*b[l-1]%P,1LL*(n/l)*(m/l))%P;}for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)B=B*f[__gcd(i,j)]%P;if(A!=B)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P3704','P3704 [SDOI2017] 数字表格',r'''定义 $g(n)=\prod_{d\mid n}f_d^{\mu(n/d)}$，则 $f_n=\prod_{d\mid n}g(d)$。因此原乘积为

$$\prod_{d=1}^{\min(n,m)}g(d)^{\lfloor n/d\rfloor\lfloor m/d\rfloor}.$$

预处理 Fibonacci、莫比乌斯函数及 $g$ 的前缀积和前缀逆积，查询时整除分块并快速幂。''',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},parts=[BB],extra=[('1\n1 1\n','1\n'),('1\n2 2\n','1\n'),('1\n3 3\n','2\n'),('1\n5 6\n','60\n')])
