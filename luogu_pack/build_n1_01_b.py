import html,json,re
from pathlib import Path
R=Path(__file__).resolve().parent.parent
def q(p):
 s=Path('/tmp/'+p+'.json').read_text();x=re.search(r'<script id="lentille-context" type="application/json">(.*?)</script>',s,re.S)
 return json.loads(html.unescape(x.group(1)))['data']['problem']
def w(n,s):
 (R/n).parent.mkdir(parents=True,exist_ok=True);(R/n).write_text(re.sub(r'[ \t]+(?=\n|$)','',s.strip())+"\n")
def add(p,b,sol,codes,parts,extra):
 x=q(p);z=x['contenu'];e=x.get('translations',{}).get('en',{});g=lambda y,k:y.get(k,'').strip()
 s=f"# {p} {z['name']}\n\n## 中文题面\n\n### 题目描述\n\n{g(z,'description')}\n\n### 输入格式\n\n{g(z,'formatI')}\n\n### 输出格式\n\n{g(z,'formatO')}"
 for i,a in enumerate(x.get('samples',[]),1):s+=f"\n\n### 样例 {i}\n\n```text\n{a[0].rstrip()}\n```\n\n```text\n{a[1].rstrip()}\n```"
 s+=f"\n\n### 说明与限制\n\n{g(z,'hint')}\n\n## English Statement\n\n### Description\n\n{g(e,'description')}\n\n### Input\n\n{g(e,'formatI')}\n\n### Output\n\n{g(e,'formatO')}\n\n### Constraints\n\n{g(e,'hint')}"
 w(b+'.md',s);w(b+' 题解.md',f'# {b} 题解\n\n{sol}')
 for k,v in codes.items():w(b+k,v)
 for i,v in enumerate(parts,1):w(f'{b} 部分分{i}.cpp',v)
 d=R/'cph'/b;d.mkdir(parents=True,exist_ok=True)
 for i,a in enumerate(x.get('samples',[]),1):w(str((d/f'{b}_{i}.in').relative_to(R)),a[0]);w(str((d/f'{b}_{i}.ans').relative_to(R)),a[1])
 k=len(x.get('samples',[]))
 for a,o in extra:k+=1;w(str((d/f'{b}_{k}.in').relative_to(R)),a);w(str((d/f'{b}_{k}.ans').relative_to(R)),o)

A='''#include <bits/stdc++.h>
using namespace std;const long long P=1e8;void f(long long n,long long&a,long long&b){if(!n){a=0;b=1;return;}long long c,d;f(n>>1,c,d);a=c*((2*d-c+P)%P)%P;b=(c*c+d*d)%P;if(n&1){c=a;a=b;b=(c+b)%P;}}
int main(){ios::sync_with_stdio(0);cin.tie(0);long long n,m,a,b;cin>>n>>m;f(__gcd(n,m),a,b);cout<<a<<'\\n';}
'''
AB='''#include <bits/stdc++.h>
using namespace std;const long long P=1e8;int main(){ios::sync_with_stdio(0);cin.tie(0);long long n,m,a=0,b=1;cin>>n>>m;n=__gcd(n,m);while(n--){long long c=(a+b)%P;a=b;b=c;}cout<<a<<'\\n';}
'''
AG='''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);cout<<g()%max(1ULL,z)+1<<' '<<g()%max(1ULL,z)+1<<'\\n';}
'''
AS='''#include <bits/stdc++.h>
using namespace std;const long long P=1e8;void f(long long n,long long&a,long long&b){if(!n){a=0;b=1;return;}long long c,d;f(n>>1,c,d);a=c*((2*d-c+P)%P)%P;b=(c*c+d*d)%P;if(n&1){c=a;a=b;b=(c+b)%P;}}int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int r=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(r--){long long n=g()%1000+1,m=g()%1000+1,k=__gcd(n,m),a,b,x=0,y=1;f(k,a,b);while(k--){long long z=(x+y)%P;x=y;y=z;}if(a!=x)return cout<<"WA\\n",1;}cout<<"OK\\n";}
'''
add('P1306','P1306 斐波那契公约数','利用恒等式 $\\gcd(F_n,F_m)=F_{\\gcd(n,m)}$，先求下标最大公约数，再用快速倍增求对应斐波那契数。时间复杂度 $O(\\log(n+m))$。',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},[],[('1 1\n','1\n'),('10 15\n','5\n'),('1000000000 999999999\n','1\n')])

B='''#include <bits/stdc++.h>
using namespace std;unsigned long long m;unsigned long long q(unsigned long long a,unsigned long long b){return(__uint128_t)a*b%m;}
int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long a,c,x,n,g,u=1,v=0;cin>>m>>a>>c>>x>>n>>g;a%=m;c%=m;x%=m;for(;n;n>>=1){if(n&1)v=(q(u,c)+v)%m,u=q(u,a);c=(q(a,c)+c)%m;a=q(a,a);}cout<<(q(u,x)+v)%m%g<<'\\n';}
'''
BB='''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long m,a,c,x,n,g;cin>>m>>a>>c>>x>>n>>g;while(n--)x=((__uint128_t)a*x+c)%m;cout<<x%g<<'\\n';}
'''
BG='''#include <bits/stdc++.h>
using namespace std;int main(int c0,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c0>1?stoull(v[1]):1,z=c0>2?stoull(v[2]):100;mt19937_64 r(s);unsigned long long m=r()%max(2ULL,z)+2;cout<<m<<' '<<r()%m<<' '<<r()%m<<' '<<r()%m<<' '<<r()%max(1ULL,z)+1<<' '<<r()%min(m,(unsigned long long)1e8)+1<<'\\n';}
'''
BS='''#include <bits/stdc++.h>
using namespace std;unsigned long long M;unsigned long long q(unsigned long long a,unsigned long long b){return(__uint128_t)a*b%M;}unsigned long long f(unsigned long long a,unsigned long long c,unsigned long long x,unsigned long long n){unsigned long long u=1,v=0;for(;n;n>>=1){if(n&1)v=(q(u,c)+v)%M,u=q(u,a);c=(q(a,c)+c)%M;a=q(a,a);}return(q(u,x)+v)%M;}int main(int c0,char**v){ios::sync_with_stdio(0);cin.tie(0);int n=c0>1?stoi(v[1]):1000;unsigned long long s=c0>2?stoull(v[2]):1;mt19937_64 g(s);while(n--){M=g()%100000+2;unsigned long long a=g()%M,c=g()%M,x=g()%M,k=g()%1000,y=x;for(int i=0;i<k;i++)y=((__uint128_t)a*y+c)%M;if(f(a,c,x,k)!=y)return cout<<"WA\\n",1;}cout<<"OK\\n";}
'''
add('P2044','P2044 [NOI2012] 随机数生成器','把一次递推看成仿射变换 $x\\mapsto ax+c$。仿射变换可结合复合，因此二进制快速幂求第 $n$ 次复合；用 `__int128` 完成模乘。时间复杂度 $O(\\log n)$。',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},[],[('2 0 0 1 1 2\n','0\n'),('100 1 1 0 99 100\n','99\n'),('1000000000000000000 1 0 999999999999999999 1000000000000000000 100000000\n','99999999\n')])

C='''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;long long a[4][4],b[4][4],c[4][4];void q(long long x[4][4],long long y[4][4]){memset(c,0,sizeof c);for(int i=0;i<4;i++)for(int k=0;k<4;k++)for(int j=0;j<4;j++)c[i][j]=(c[i][j]+x[i][k]*y[k][j])%P;memcpy(x,c,sizeof c);}
int main(){ios::sync_with_stdio(0);cin.tie(0);int t;cin>>t;while(t--){long long n,u,v,x,y;cin>>n>>u>>v>>x>>y;u%=P;v%=P;x%=P;y%=P;if(n==1){cout<<u*u%P<<'\\n';continue;}memset(a,0,sizeof a);memset(b,0,sizeof b);a[0][0]=a[3][0]=x*x%P;a[0][1]=a[3][1]=y*y%P;a[0][2]=a[3][2]=2*x%P*y%P;a[1][0]=1;a[2][0]=x;a[2][2]=y;a[3][3]=1;for(int i=0;i<4;i++)b[i][i]=1;for(n-=2;n;n>>=1,q(a,a))if(n&1)q(b,a);long long r=(u*u+v*v)%P;cout<<(b[3][0]*v%P*v+b[3][1]*u%P*u+b[3][2]*u%P*v+b[3][3]*r)%P<<'\\n';}}
'''
CB='''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;int main(){ios::sync_with_stdio(0);cin.tie(0);int t;cin>>t;while(t--){long long n,a,b,x,y,s;cin>>n>>a>>b>>x>>y;a%=P;b%=P;s=a*a%P;if(n>1)s=(s+b*b)%P;for(int i=3;i<=n;i++){long long c=(x%P*b+y%P*a)%P;a=b;b=c;s=(s+b*b)%P;}cout<<s<<'\\n';}}
'''
CG='''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);int t=min(30ULL,max(1ULL,z/10));cout<<t<<'\\n';while(t--)cout<<g()%max(1ULL,z)+1<<' '<<g()%1000000000+1<<' '<<g()%1000000000+1<<' '<<g()%1000000000+1<<' '<<g()%1000000000+1<<'\\n';}
'''
CS='''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;long long a[4][4],b[4][4],c[4][4];void q(long long x[4][4],long long y[4][4]){memset(c,0,sizeof c);for(int i=0;i<4;i++)for(int k=0;k<4;k++)for(int j=0;j<4;j++)c[i][j]=(c[i][j]+x[i][k]*y[k][j])%P;memcpy(x,c,sizeof c);}long long f(long long n,long long u,long long v,long long x,long long y){u%=P;v%=P;x%=P;y%=P;if(n==1)return u*u%P;memset(a,0,sizeof a);memset(b,0,sizeof b);a[0][0]=a[3][0]=x*x%P;a[0][1]=a[3][1]=y*y%P;a[0][2]=a[3][2]=2*x%P*y%P;a[1][0]=1;a[2][0]=x;a[2][2]=y;a[3][3]=1;for(int i=0;i<4;i++)b[i][i]=1;for(n-=2;n;n>>=1,q(a,a))if(n&1)q(b,a);return(b[3][0]*v%P*v+b[3][1]*u%P*u+b[3][2]*u%P*v+b[3][3]*(u*u%P+v*v)%P)%P;}int main(int c0,char**v){ios::sync_with_stdio(0);cin.tie(0);int r=c0>1?stoi(v[1]):1000;unsigned long long s=c0>2?stoull(v[2]):1;mt19937_64 g(s);while(r--){long long n=g()%50+1,u=g()%100,v=g()%100,x=g()%100,y=g()%100,A=u%P,B=v%P,z=A*A%P;if(n>1)z=(z+B*B)%P;for(int i=3;i<=n;i++){long long C=(x*B+y*A)%P;A=B;B=C;z=(z+B*B)%P;}if(f(n,u,v,x,y)!=z)return cout<<"WA\\n",1;}cout<<"OK\\n";}
'''
add('P5175','P5175 数列','平方递推会同时出现 $a_n^2$、$a_{n-1}^2$ 与 $a_na_{n-1}$。把这三项和平方和一起组成四维状态，矩阵快速幂求解。时间复杂度 $O(T\\log n)$。',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},[C],[('1\n1 7 9 2 3\n','49\n'),('1\n2 7 9 2 3\n','130\n'),('1\n3 1 2 3 4\n','105\n')])

D='''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;const int N=105;long long a[N][N],b[N][N],c[N][N];int n;void q(long long x[N][N],long long y[N][N]){memset(c,0,sizeof c);for(int i=0;i<n;i++)for(int k=0;k<n;k++)for(int j=0;j<n;j++)c[i][j]=(c[i][j]+x[i][k]*y[k][j])%P;memcpy(x,c,sizeof c);}
int main(){ios::sync_with_stdio(0);cin.tie(0);long long k;cin>>n>>k;for(int i=0;i<n;i++)for(int j=0;j<n;j++){cin>>a[i][j];a[i][j]=(a[i][j]%P+P)%P;}for(int i=0;i<n;i++)b[i][i]=1;for(;k;k>>=1,q(a,a))if(k&1)q(b,a);for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<(j?" ":"")<<b[i][j];cout<<'\\n';}}
'''
DB='''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;const int N=105;long long a[N][N],b[N][N],c[N][N];int n;int main(){ios::sync_with_stdio(0);cin.tie(0);int k;cin>>n>>k;for(int i=0;i<n;i++)for(int j=0;j<n;j++){cin>>a[i][j];a[i][j]=(a[i][j]%P+P)%P;b[i][j]=i==j;}while(k--){memset(c,0,sizeof c);for(int i=0;i<n;i++)for(int z=0;z<n;z++)for(int j=0;j<n;j++)c[i][j]=(c[i][j]+b[i][z]*a[z][j])%P;memcpy(b,c,sizeof c);}for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<(j?" ":"")<<b[i][j];cout<<'\\n';}}
'''
DG='''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):10;mt19937_64 g(s);int n=g()%min(100ULL,max(1ULL,z))+1;cout<<n<<' '<<g()%max(1ULL,z)<<'\\n';for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<(long long)(g()%2001)-1000<<' ';cout<<'\\n';}}
'''
DS='''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;long long a[7][7],b[7][7],c[7][7],d[7][7],e[7][7];int n;void q(long long x[7][7],long long y[7][7]){memset(c,0,sizeof c);for(int i=0;i<n;i++)for(int k=0;k<n;k++)for(int j=0;j<n;j++)c[i][j]=(c[i][j]+x[i][k]*y[k][j])%P;memcpy(x,c,sizeof c);}int main(int c0,char**v){ios::sync_with_stdio(0);cin.tie(0);int r=c0>1?stoi(v[1]):1000;unsigned long long s=c0>2?stoull(v[2]):1;mt19937_64 g(s);while(r--){n=g()%6+1;int k=g()%20;memset(a,0,sizeof a);memset(b,0,sizeof b);for(int i=0;i<n;i++)for(int j=0;j<n;j++)d[i][j]=a[i][j]=g()%100,b[i][j]=e[i][j]=i==j;int z=k;for(;z;z>>=1,q(a,a))if(z&1)q(b,a);while(k--){memset(c,0,sizeof c);for(int i=0;i<n;i++)for(int h=0;h<n;h++)for(int j=0;j<n;j++)c[i][j]=(c[i][j]+e[i][h]*d[h][j])%P;memcpy(e,c,sizeof c);}for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(b[i][j]!=e[i][j])return cout<<"WA\\n",1;}cout<<"OK\\n";}
'''
add('P3390','P3390 【模板】矩阵快速幂','矩阵乘法满足结合律，按指数二进制位进行快速幂。初始答案为单位矩阵，输入负数先规范到模域。时间复杂度 $O(n^3\\log k)$。',{'.cpp':D,' 数据生成.cpp':DG,' 暴力.cpp':DB,' 对拍.cpp':DS},[],[('1 0\n-5\n','1\n'),('1 3\n-2\n','999999999\n')])
