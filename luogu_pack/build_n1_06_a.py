from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);long long n,k,r;cin>>n>>k;r=n*k;for(long long l=1,m=min(n,k),q;l<=m;l=q+1){q=min(m,k/(k/l));r-=k/l*(l+q)*(q-l+1)/2;}cout<<r<<'\n';}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);long long n,k,r=0;cin>>n>>k;for(int i=1;i<=n;i++)r+=k%i;cout<<r<<'\n';}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):1000000000;mt19937_64 g(s);z=min(1000000000ULL,max(1ULL,z));cout<<g()%z+1<<' '<<g()%z+1<<'\n';}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){long long n=g()%1000+1,k=g()%1000+1,a=n*k,b=0;for(long long l=1,m=min(n,k),r;l<=m;l=r+1){r=min(m,k/(k/l));a-=k/l*(l+r)*(r-l+1)/2;}for(int i=1;i<=n;i++)b+=k%i;if(a!=b)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P2261','P2261 [CQOI2007] 余数求和',r'''由 $k\bmod i=k-i\lfloor k/i\rfloor$，答案为

$$nk-\sum_{i=1}^{\min(n,k)}i\left\lfloor\frac{k}{i}\right\rfloor.$$

$\lfloor k/i\rfloor$ 只有 $O(\sqrt k)$ 段相同值，每段用等差数列求和，复杂度 $O(\sqrt k)$。''',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},parts=[AB],extra=[('1 1\n','0\n'),('5 1\n','4\n'),('3 10\n','1\n'),('100 100\n','1701\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;const long long P=998244353;long long f(long long n){long long r=0;for(long long l=1,q;l<=n;l=q+1){q=n/(n/l);r=(r+(q-l+1)%P*(n/l))%P;}return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);long long l,r;cin>>l>>r;cout<<(f(r)-f(l-1)+P)%P<<'\n';}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;const long long P=998244353;int main(){ios::sync_with_stdio(0);cin.tie(0);long long l,r,a=0;cin>>l>>r;for(long long x=l;x<=r;x++)for(long long d=1;d*d<=x;d++)if(x%d==0)a+=1+(d*d<x);cout<<a%P<<'\n';}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):160000000000000ULL;mt19937_64 g(s);z=min(160000000000000ULL,max(1ULL,z));unsigned long long r=g()%z+1,l=g()%r+1;cout<<l<<' '<<r<<'\n';}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;const long long P=998244353;long long f(long long n){long long r=0;for(long long l=1,q;l<=n;l=q+1){q=n/(n/l);r=(r+(q-l+1)%P*(n/l))%P;}return r;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int l=g()%1000+1,r=l+g()%100;long long a=(f(r)-f(l-1)+P)%P,b=0;for(int x=l;x<=r;x++)for(int d=1;d*d<=x;d++)if(x%d==0)b+=1+(d*d<x);if(a!=b%P)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P3935','P3935 Calculating',r'''$f(x)$ 就是约数个数 $\tau(x)$。交换枚举顺序可得其前缀和

$$F(n)=\sum_{x=1}^n\tau(x)=\sum_{d=1}^n\left\lfloor\frac nd\right\rfloor.$$

对整除商分块求 $F(r)-F(l-1)$，每次前缀计算为 $O(\sqrt n)$。''',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},parts=[BB],extra=[('1 1\n','1\n'),('1 10\n','27\n'),('10 20\n','43\n'),('100 200\n','625\n')])

C=r'''#include <bits/stdc++.h>
using namespace std;const int V=2000000;const long long P=1000000007;int p[V+5],v[V+5],u[V+5],s[V+5];unordered_map<long long,long long>h;long long M(long long n){if(n<=V)return s[n];auto t=h.find(n);if(t!=h.end())return t->second;long long r=1;for(long long l=2,q;l<=n;l=q+1){q=n/(n/l);r-=(q-l+1)*M(n/l);}return h[n]=r;}long long q(long long a,long long b){long long r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int z=0;u[1]=1;for(int i=2;i<=V;i++){if(!v[i])p[z++]=i,u[i]=-1;for(int j=0;j<z&&1LL*i*p[j]<=V;j++){v[i*p[j]]=1;if(i%p[j]==0){u[i*p[j]]=0;break;}u[i*p[j]]=-u[i];}}for(int i=1;i<=V;i++)s[i]=s[i-1]+u[i];long long n,k,L,H;cin>>n>>k>>L>>H;long long a=(L+k-1)/k,b=H/k;if(a>b)return cout<<0<<'\n',0;long long r=0;for(long long l=1,d;l<=b;l=d+1){long long x=b/l,y=(a-1)/l,d1=b/x,d2=y?(a-1)/y:b;d=min(d1,d2);long long c=x-y;r=(r+(M(d)-M(l-1))%P*q(c,n))%P;}cout<<(r+P)%P<<'\n';}
'''
CB=r'''#include <bits/stdc++.h>
using namespace std;const long long P=1000000007;long long n,k,l,h,r;void d(int x,long long g){if(x==n){r+=g==k;return;}for(long long i=l;i<=h;i++)d(x+1,__gcd(g,i));}int main(){ios::sync_with_stdio(0);cin.tie(0);cin>>n>>k>>l>>h;d(0,0);cout<<r%P<<'\n';}
'''
CG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100000;mt19937_64 g(s);long long n=g()%1000000000+1,k=g()%1000000000+1,l=g()%1000000000+1,w=g()%min(100000ULL,max(1ULL,z));cout<<n<<' '<<k<<' '<<l<<' '<<min(1000000000LL,l+w)<<'\n';}
'''
CS=r'''#include <bits/stdc++.h>
using namespace std;const long long P=1000000007;int u[105];long long q(long long a,long long b){long long r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}long long n,k,l,h,A;void d(int x,long long g){if(x==n){A+=g==k;return;}for(long long i=l;i<=h;i++)d(x+1,__gcd(g,i));}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long z=C>2?stoull(v[2]):1;mt19937_64 g(z);u[1]=1;for(int i=1;i<=100;i++)for(int j=i+i;j<=100;j+=i)u[j]-=u[i];while(R--){n=g()%4+1;k=g()%5+1;l=g()%8+1;h=l+g()%5;long long a=(l+k-1)/k,b=h/k,B=0;A=0;if(a<=b)for(int x=1;x<=b;x++){int c=b/x-(a-1)/x;B=(B+u[x]*q(c,n))%P;}d(0,0);if((B+P)%P!=A%P)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P3172','P3172 [CQOI2015] 选数',r'''把所有数除以 $K$，区间变为 $[A,B]=[\lceil L/K\rceil,\lfloor H/K\rfloor]$，目标变成 gcd 为一。莫比乌斯反演得到

$$\sum_{d=1}^{B}\mu(d)\left(\left\lfloor\frac Bd\right\rfloor-\left\lfloor\frac{A-1}{d}\right\rfloor\right)^N.$$

括号内的值可整除分块；每段的 $\mu$ 和用杜教筛求 Mertens 函数，复杂度约 $O(B^{2/3})$。''',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},extra=[('1 1 1 1\n','1\n'),('2 1 1 3\n','7\n'),('3 2 2 6\n','25\n'),('2 5 1 4\n','0\n')])
