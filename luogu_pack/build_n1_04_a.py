from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int x,y;cin>>x>>y;if(y%x)return cout<<0<<'\n',0;int n=y/x,r=1;for(int p=2;1LL*p*p<=n;p++)if(n%p==0){r*=2;while(n%p==0)n/=p;}if(n>1)r*=2;cout<<r<<'\n';}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int x,y,r=0;cin>>x>>y;for(int a=x;a<=y;a+=x)for(int b=x;b<=y;b+=x)if(__gcd(a,b)==x&&1LL*a/__gcd(a,b)*b==y)r++;cout<<r<<'\n';}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100000;mt19937_64 g(s);int m=min(100000ULL,max(2ULL,z)),x=g()%(m-1)+2,y=x*(g()%max(1,100000/x)+1);cout<<x<<' '<<y<<'\n';}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int x=g()%50+1,y=x*(g()%50+1),n=y/x,a=1,b=0;for(int p=2;p*p<=n;p++)if(n%p==0){a*=2;while(n%p==0)n/=p;}if(n>1)a*=2;for(int i=x;i<=y;i+=x)for(int j=x;j<=y;j+=x)if(__gcd(i,j)==x&&1LL*i/__gcd(i,j)*j==y)b++;if(a!=b)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P1029','P1029 [NOIP 2001 普及组] 最大公约数和最小公倍数问题',r'令 $P=x_0a,Q=x_0b$，则 $ab=y_0/x_0$ 且 $\gcd(a,b)=1$。每个不同质因子的完整质数幂只能放到 $a,b$ 中的一边，因此若商有 $k$ 个不同质因子，答案为 $2^k$；不能整除时为零。',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},extra=[('2 2\n','1\n'),('2 12\n','4\n'),('6 180\n','8\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;const int V=1000005,N=10005;int c[V],a[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m=0;cin>>n;for(int i=0,x;i<n;i++)cin>>x,c[x]++,m=max(m,x);int k=0;for(int d=m;d;d--){int s=0;for(int j=d;j<=m;j+=d)s+=c[j];while(k<s)a[++k]=d;}for(int i=1;i<=n;i++)cout<<a[i]<<'\n';}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;const int N=18;int a[N],p[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>a[i];for(int s=1;s<(1<<n);s++){int k=__builtin_popcount((unsigned)s),g=0;for(int i=0;i<n;i++)if(s>>i&1)g=__gcd(g,a[i]);p[k]=max(p[k],g);}for(int i=1;i<=n;i++)cout<<p[i]<<'\n';}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(10000ULL,max(1ULL,z))+1;cout<<n<<'\n';while(n--)cout<<g()%1000000+1<<' ';cout<<'\n';}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;const int N=18,V=105;int a[N],c[V],x[N],y[N];int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%14+1;memset(c,0,sizeof c);memset(x,0,sizeof x);memset(y,0,sizeof y);for(int i=0;i<n;i++)a[i]=g()%100+1,c[a[i]]++;int k=0;for(int d=100;d;d--){int q=0;for(int j=d;j<=100;j+=d)q+=c[j];while(k<q)x[k++]=d;}for(int z=1;z<(1<<n);z++){int q=__builtin_popcount((unsigned)z),d=0;for(int i=0;i<n;i++)if(z>>i&1)d=__gcd(d,a[i]);y[q-1]=max(y[q-1],d);}for(int i=0;i<n;i++)if(x[i]!=y[i])return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P1414','P1414 又是毕业季II',r'统计每个能力值出现次数。对每个 $d$ 求所有 $d$ 的倍数的出现总数 $c_d$，表示最多有 $c_d$ 个人能组成 gcd 至少为 $d$ 的集合。按 $d$ 从大到小扫描，依次填充尚未得到答案的队伍规模。复杂度 $O(V\log V)$。',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},parts=[BB],extra=[('1\n7\n','7\n'),('3\n6 10 15\n','15\n5\n1\n'),('4\n8 16 24 32\n','32\n16\n8\n8\n')])

C=r'''#include <bits/stdc++.h>
using namespace std;const int N=2005;long long d[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){long long a,b,c,n;cin>>a>>b>>c>>n;int k=0;for(long long i=1;i*i<=n;i++)if(n%i==0){d[k++]=i;if(i*i<n)d[k++]=n/i;}int r=0;for(int i=0;i<k;i++)if(__gcd(d[i],a)==b&&d[i]/__gcd(d[i],c)*c==n)r++;cout<<r<<'\n';}}
'''
CB=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){long long a,b,c,d,r=0;cin>>a>>b>>c>>d;for(long long x=1;x<=d;x++)if(__gcd(x,a)==b&&x/__gcd(x,c)*c==d)r++;cout<<r<<'\n';}}
'''
CG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int T=g()%min(2000ULL,max(1ULL,z))+1;cout<<T<<'\n';while(T--){int x=g()%1000+1,a=x*(g()%100+1),b=__gcd(x,a),c=g()%1000+1,d=1LL*x/__gcd(x,c)*c;cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';}}
'''
CS=r'''#include <bits/stdc++.h>
using namespace std;long long x[1000];int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){long long a=g()%100+1,b=g()%100+1,c=g()%100+1,d=g()%100+1,k=0,A=0,B=0;for(long long i=1;i*i<=d;i++)if(d%i==0){x[k++]=i;if(i*i<d)x[k++]=d/i;}for(int i=0;i<k;i++)if(__gcd(x[i],a)==b&&x[i]/__gcd(x[i],c)*c==d)A++;for(long long i=1;i<=d;i++)if(__gcd(i,a)==b&&i/__gcd(i,c)*c==d)B++;if(A!=B)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P1072','P1072 [NOIP 2009 提高组] Hankson 的趣味题',r'由 $\operatorname{lcm}(x,b_0)=b_1$ 可知 $x\mid b_1$。枚举 $b_1$ 的全部约数，只需逐个检查 $\gcd(x,a_0)=a_1$ 与最小公倍数条件。一个不超过 $2\times10^9$ 的数约数很少，复杂度主要为每组 $O(\sqrt{b_1})$ 的约数生成。',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},parts=[CB],extra=[('1\n1 1 1 1\n','1\n'),('1\n12 4 6 12\n','1\n'),('2\n10 2 3 30\n20 5 6 60\n','0\n0\n')])

D=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long g=0,x;cin>>n;while(n--)cin>>x,g=__gcd(g,abs(x));cout<<g<<'\n';}
'''
DB=D
DG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(20ULL,max(1ULL,z))+1;cout<<n<<'\n';while(n--)cout<<(int)(g()%200001)-100000<<' ';cout<<'\n';}
'''
DS=r'''#include <bits/stdc++.h>
using namespace std;int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 q(s);while(R--){int n=q()%20+1;long long g=0;for(int i=0;i<n;i++){long long x=(int)(q()%200001)-100000;g=__gcd(g,abs(x));}if(g<0)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P4549','P4549 【模板】裴蜀定理',r'所有整数线性组合能得到的正整数恰好是 $\gcd(|A_1|,\ldots,|A_n|)$ 的正倍数，因此最小正值就是全体绝对值的最大公约数。',{'.cpp':D,' 数据生成.cpp':DG,' 暴力.cpp':DB,' 对拍.cpp':DS},extra=[('1\n-7\n','7\n'),('3\n6 -10 14\n','2\n'),('4\n0 12 18 -30\n','6\n')])
