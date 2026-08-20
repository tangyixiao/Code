import html,json,re
from pathlib import Path

R=Path(__file__).resolve().parent.parent

def q(p):
 s=Path('/tmp/'+p+'.json').read_text()
 x=re.search(r'<script id="lentille-context" type="application/json">(.*?)</script>',s,re.S)
 return json.loads(html.unescape(x.group(1)))['data']['problem']

def w(n,s):
 (R/n).parent.mkdir(parents=True,exist_ok=True)
 (R/n).write_text(re.sub(r'[ \t]+(?=\n|$)','',s.strip())+"\n")

def add(p,b,sol,codes,partials):
 x=q(p);z=x['contenu'];e=x.get('translations',{}).get('en',{})
 def sec(y,k): return y.get(k,'').strip()
 s=f"# {p} {z['name']}\n\n## 中文题面\n\n### 题目描述\n\n{sec(z,'description')}\n\n### 输入格式\n\n{sec(z,'formatI')}\n\n### 输出格式\n\n{sec(z,'formatO')}"
 for i,a in enumerate(x.get('samples',[]),1): s+=f"\n\n### 样例 {i}\n\n```text\n{a[0].rstrip()}\n```\n\n```text\n{a[1].rstrip()}\n```"
 s+=f"\n\n### 说明与限制\n\n{sec(z,'hint')}\n\n## English Statement\n\n### Description\n\n{sec(e,'description')}\n\n### Input\n\n{sec(e,'formatI')}\n\n### Output\n\n{sec(e,'formatO')}\n\n### Constraints\n\n{sec(e,'hint')}"
 w(b+'.md',s);w(b+' 题解.md',f"# {b} 题解\n\n{sol}")
 for k,v in codes.items():w(b+k,v)
 for i,v in enumerate(partials,1):w(f'{b} 部分分{i}.cpp',v)
 d=R/'cph'/b;d.mkdir(parents=True,exist_ok=True)
 for i,a in enumerate(x.get('samples',[]),1):
  w(str((d/f'{b}_{i}.in').relative_to(R)),a[0]);w(str((d/f'{b}_{i}.ans').relative_to(R)),a[1])

A='''#include <bits/stdc++.h>
using namespace std;
long long q(long long a,long long b,long long p){long long r=1%p;for(;b;b>>=1,a=(__int128)a*a%p)if(b&1)r=(__int128)r*a%p;return r;}
int main(){ios::sync_with_stdio(0);cin.tie(0);long long a,b,p;cin>>a>>b>>p;cout<<a<<'^'<<b<<" mod "<<p<<'='<<q(a,b,p)<<'\\n';}
'''
AB='''#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(0);cin.tie(0);long long a,b,p,r=1;cin>>a>>b>>p;for(long long i=0;i<b;i++)r=(__int128)r*a%p;cout<<a<<'^'<<b<<" mod "<<p<<'='<<r<<'\\n';}
'''
AG='''#include <bits/stdc++.h>
using namespace std;
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);long long p=g()%max(2ULL,z)+2,a=g()%max(1LL,p),b=g()%max(1ULL,z);cout<<a<<' '<<b<<' '<<p<<'\\n';}
'''
AS='''#include <bits/stdc++.h>
using namespace std;
long long q(long long a,long long b,long long p){long long r=1%p;for(;b;b>>=1,a=(__int128)a*a%p)if(b&1)r=(__int128)r*a%p;return r;}
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int n=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(n--){long long p=g()%100000+2,a=g()%p,b=g()%80,r=1%p;for(int i=0;i<b;i++)r=(__int128)r*a%p;if(q(a,b,p)!=r)return cout<<"WA\\n",1;}cout<<"OK\\n";}
'''
add('P1226','P1226 【模板】快速幂','二进制拆分指数。维护当前底数与已选位的乘积，每轮平方底数并右移指数。乘法用 `__int128` 规避中间值溢出。时间复杂度 $O(\\log b)$，空间复杂度 $O(1)$。',{' .cpp'.replace(' ', ''):A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},[])

B='''#include <bits/stdc++.h>
using namespace std;
const int N=205;const long long I=4e18;long long a[N][N],b[N][N],c[N][N],d[N][N];int h[1005],x[N];
void m(long long a[N][N],long long b[N][N],long long c[N][N],int n){for(int i=0;i<n;i++)for(int j=0;j<n;j++)d[i][j]=I;for(int i=0;i<n;i++)for(int k=0;k<n;k++)if(a[i][k]<I)for(int j=0;j<n;j++)if(b[k][j]<I)d[i][j]=min(d[i][j],a[i][k]+b[k][j]);for(int i=0;i<n;i++)for(int j=0;j<n;j++)c[i][j]=d[i][j];}
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,t,s,e,k=0;cin>>n>>t>>s>>e;memset(h,-1,sizeof h);for(int i=0;i<N;i++)for(int j=0;j<N;j++)a[i][j]=I;while(t--){int w,u,v;cin>>w>>u>>v;if(h[u]<0)h[u]=k++;if(h[v]<0)h[v]=k++;a[h[u]][h[v]]=a[h[v]][h[u]]=w;}for(int i=0;i<k;i++)for(int j=0;j<k;j++)b[i][j]=i==j?0:I;for(;n;n>>=1,m(a,a,a,k))if(n&1)m(b,a,b,k);cout<<b[h[s]][h[e]]<<'\\n';}
'''
BB='''#include <bits/stdc++.h>
using namespace std;
const int N=205;const long long I=4e18;long long a[N][N],f[N],g[N];int h[1005];
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,t,s,e,k=0;cin>>n>>t>>s>>e;memset(h,-1,sizeof h);for(int i=0;i<N;i++)for(int j=0;j<N;j++)a[i][j]=I;while(t--){int w,u,v;cin>>w>>u>>v;if(h[u]<0)h[u]=k++;if(h[v]<0)h[v]=k++;a[h[u]][h[v]]=a[h[v]][h[u]]=w;}fill(f,f+k,I);f[h[s]]=0;while(n--){fill(g,g+k,I);for(int i=0;i<k;i++)for(int j=0;j<k;j++)if(f[i]<I&&a[i][j]<I)g[j]=min(g[j],f[i]+a[i][j]);copy(g,g+k,f);}cout<<f[h[e]]<<'\\n';}
'''
BG='''#include <bits/stdc++.h>
using namespace std;
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):8;mt19937_64 g(s);int n=g()%max(2ULL,z)+1,k=g()%min(8ULL,max(2ULL,z))+2,t=k*(k-1)/2;cout<<n<<' '<<t<<" 1 "<<k<<'\\n';for(int i=1;i<=k;i++)for(int j=i+1;j<=k;j++)cout<<g()%30+1<<' '<<i<<' '<<j<<'\\n';}
'''
BS='''#include <bits/stdc++.h>
using namespace std;
const long long I=4e18;long long a[9][9],b[9][9],c[9][9],d[9][9],e[9][9],f[9],g[9];
void m(long long a[9][9],long long b[9][9],long long c[9][9],int n){for(int i=0;i<n;i++)for(int j=0;j<n;j++)d[i][j]=I;for(int i=0;i<n;i++)for(int k=0;k<n;k++)for(int j=0;j<n;j++)d[i][j]=min(d[i][j],a[i][k]+b[k][j]);memcpy(c,d,sizeof d);}
int main(int c0,char**v){ios::sync_with_stdio(0);cin.tie(0);int r=c0>1?stoi(v[1]):1000;unsigned long long s=c0>2?stoull(v[2]):1;mt19937_64 q(s);while(r--){int n=q()%10+1,k=q()%7+2;for(int i=0;i<k;i++)for(int j=0;j<k;j++)e[i][j]=a[i][j]=i==j?I:q()%30+1,b[i][j]=i==j?0:I;int z=n;for(;z;z>>=1,m(a,a,a,k))if(z&1)m(b,a,b,k);fill(f,f+k,I);f[0]=0;for(int z=0;z<n;z++){fill(g,g+k,I);for(int i=0;i<k;i++)for(int j=0;j<k;j++)g[j]=min(g[j],f[i]+e[i][j]);copy(g,g+k,f);}if(b[0][k-1]!=f[k-1])return cout<<"WA\\n",1;}cout<<"OK\\n";}
'''
add('P2886','P2886 [USACO07NOV] Cow Relays G','把出现的路口离散化。邻接矩阵在最小加法半环上相乘：乘法改为加法，加法改为取最小值。矩阵的 $N$ 次幂就记录恰好经过 $N$ 条边的最短路。时间复杂度 $O(V^3\\log N)$。',{' .cpp'.replace(' ', ''):B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},[])

C='''#include <bits/stdc++.h>
using namespace std;
long long m,x[2][2],y[2][2],z[2][2];void q(long long a[2][2],long long b[2][2]){memset(z,0,sizeof z);for(int i=0;i<2;i++)for(int k=0;k<2;k++)for(int j=0;j<2;j++)z[i][j]=(z[i][j]+(__int128)a[i][k]*b[k][j])%m;memcpy(a,z,sizeof z);}
int main(){ios::sync_with_stdio(0);cin.tie(0);long long p,r,a,b,n;cin>>p>>r>>a>>b>>n>>m;if(n==1)return cout<<a%m<<'\\n',0;x[0][0]=p%m;x[0][1]=r%m;x[1][0]=1;y[0][0]=y[1][1]=1;for(n-=2;n;n>>=1,q(x,x))if(n&1)q(y,x);cout<<(long long)(((__int128)y[0][0]*(b%m)+(__int128)y[0][1]*(a%m))%m)<<'\\n';}
'''
CB='''#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(0);cin.tie(0);long long p,q,a,b,n,m;cin>>p>>q>>a>>b>>n>>m;a%=m;b%=m;for(long long i=3;i<=n;i++){long long c=((__int128)p*b+(__int128)q*a)%m;a=b;b=c;}cout<<(n==1?a:b)<<'\\n';}
'''
CG='''#include <bits/stdc++.h>
using namespace std;
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);long long m=g()%max(2ULL,z)+2;cout<<g()%z<<' '<<g()%z<<' '<<g()%z<<' '<<g()%z<<' '<<g()%max(1ULL,z)+1<<' '<<m<<'\\n';}
'''
CS='''#include <bits/stdc++.h>
using namespace std;
long long x[2][2],y[2][2],z[2][2],M;void q(long long a[2][2],long long b[2][2]){memset(z,0,sizeof z);for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)z[i][j]=(z[i][j]+(__int128)a[i][k]*b[k][j])%M;memcpy(a,z,sizeof z);}long long f(long long p,long long q,long long a,long long b,long long n,long long m){a%=m;b%=m;for(int i=3;i<=n;i++){long long c=((__int128)p*b+(__int128)q*a)%m;a=b;b=c;}return n==1?a:b;}long long g(long long p,long long r,long long a,long long b,long long n,long long m){if(n<3)return (n==1?a:b)%m;M=m;memset(x,0,sizeof x);memset(y,0,sizeof y);x[0][0]=p%m;x[0][1]=r%m;x[1][0]=1;y[0][0]=y[1][1]=1;for(n-=2;n;n>>=1,q(x,x))if(n&1)q(y,x);return ((__int128)y[0][0]*b+(__int128)y[0][1]*a)%m;}
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int r=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 e(s);while(r--){long long p=e()%100,q=e()%100,a=e()%100,b=e()%100,n=e()%100+1,m=e()%999+2;if(f(p,q,a,b,n,m)!=g(p,q,a,b,n,m))return cout<<"WA\\n",1;}cout<<"OK\\n";}
'''
add('P1349','P1349 广义斐波那契数列','把 $[a_i,a_{i-1}]^T$ 写成二阶转移矩阵。快速幂求出第 $n$ 项，所有运算随时对 $m$ 取模。时间复杂度 $O(\\log n)$。',{' .cpp'.replace(' ', ''):C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},[])

D='''#include <bits/stdc++.h>
using namespace std;
const long long P=1e9+7;long long x[3][3],y[3][3],z[3][3];void q(long long a[3][3],long long b[3][3]){memset(z,0,sizeof z);for(int i=0;i<3;i++)for(int k=0;k<3;k++)for(int j=0;j<3;j++)z[i][j]=(z[i][j]+a[i][k]*b[k][j])%P;memcpy(a,z,sizeof z);}
int main(){ios::sync_with_stdio(0);cin.tie(0);int t;cin>>t;while(t--){long long n;cin>>n;if(n<4){cout<<1<<'\\n';continue;}memset(x,0,sizeof x);memset(y,0,sizeof y);x[0][0]=x[0][2]=x[1][0]=x[2][1]=1;y[0][0]=y[1][1]=y[2][2]=1;for(n-=3;n;n>>=1,q(x,x))if(n&1)q(y,x);cout<<(y[0][0]+y[0][1]+y[0][2])%P<<'\\n';}}
'''
DB='''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;int main(){ios::sync_with_stdio(0);cin.tie(0);int t;cin>>t;while(t--){int n;cin>>n;long long a=1,b=1,c=1;for(int i=4;i<=n;i++){long long d=(a+c)%P;a=b;b=c;c=d;}cout<<(n<4?1:c)<<'\\n';}}
'''
DG='''#include <bits/stdc++.h>
using namespace std;
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);int t=min(100ULL,max(1ULL,z/10));cout<<t<<'\\n';while(t--)cout<<g()%max(1ULL,z)+1<<'\\n';}
'''
DS='''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;long long a[1005],x[3][3],y[3][3],z[3][3];void q(long long b[3][3],long long c[3][3]){memset(z,0,sizeof z);for(int i=0;i<3;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)z[i][j]=(z[i][j]+b[i][k]*c[k][j])%P;memcpy(b,z,sizeof z);}long long f(long long n){if(n<4)return 1;memset(x,0,sizeof x);memset(y,0,sizeof y);x[0][0]=x[0][2]=x[1][0]=x[2][1]=1;y[0][0]=y[1][1]=y[2][2]=1;for(n-=3;n;n>>=1,q(x,x))if(n&1)q(y,x);return(y[0][0]+y[0][1]+y[0][2])%P;}
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int r=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);a[1]=a[2]=a[3]=1;for(int i=4;i<=1000;i++)a[i]=(a[i-1]+a[i-3])%P;while(r--){int n=g()%1000+1;if(f(n)!=a[n])return cout<<"WA\\n",1;}cout<<"OK\\n";}
'''
add('P1939','P1939 矩阵加速（数列）','状态取连续三项，转移矩阵第一行为 $(1,0,1)$。对矩阵做二进制快速幂即可回答每次询问。时间复杂度 $O(T\\log n)$。',{' .cpp'.replace(' ', ''):D,' 数据生成.cpp':DG,' 暴力.cpp':DB,' 对拍.cpp':DS},[DB,DB])

def cases(b,a):
 d=R/'cph'/b
 k=1
 for s,t in a:
  k+=1;w(str((d/f'{b}_{k}.in').relative_to(R)),s);w(str((d/f'{b}_{k}.ans').relative_to(R)),t)

cases('P1226 【模板】快速幂',[
 ('0 5 7\n','0^5 mod 7=0\n'),('5 0 13\n','5^0 mod 13=1\n'),
 ('2147483647 2147483647 2147483646\n',f'2147483647^2147483647 mod 2147483646={pow(2147483647,2147483647,2147483646)}\n')])
cases('P2886 [USACO07NOV] Cow Relays G',[
 ('1 3 1 3\n5 1 2\n2 2 3\n10 1 3\n','10\n'),
 ('2 3 1 3\n5 1 2\n2 2 3\n10 1 3\n','7\n'),
 ('3 3 1 3\n5 1 2\n2 2 3\n10 1 3\n','14\n')])
cases('P1349 广义斐波那契数列',[
 ('1 1 1 1 1 7\n','1\n'),('1 1 1 1 10 7\n','6\n'),('0 0 9 8 100 13\n','0\n')])
cases('P1939 矩阵加速（数列）',[
 ('3\n1\n2\n3\n','1\n1\n1\n'),('3\n4\n5\n10\n','2\n3\n19\n'),('1\n100\n','630106336\n')])
