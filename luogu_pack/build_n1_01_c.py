import html,json,re
from pathlib import Path
R=Path(__file__).resolve().parent.parent
def q(p):
 s=Path('/tmp/'+p+'.json').read_text();x=re.search(r'<script id="lentille-context" type="application/json">(.*?)</script>',s,re.S)
 return json.loads(html.unescape(x.group(1)))['data']['problem']
def w(n,s):(R/n).parent.mkdir(parents=True,exist_ok=True);(R/n).write_text(re.sub(r'[ \t]+(?=\n|$)','',s.strip())+"\n")
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
using namespace std;const long long P=1e9+7;const int N=405;long long a[N][N*2];long long q(long long a,long long n){long long r=1;for(;n;n>>=1,a=a*a%P)if(n&1)r=r*a%P;return r;}
int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++){for(int j=0;j<n;j++)cin>>a[i][j];a[i][i+n]=1;}for(int i=0;i<n;i++){int k=i;while(k<n&&!a[k][i])k++;if(k==n)return cout<<"No Solution\\n",0;for(int j=0;j<2*n;j++)swap(a[i][j],a[k][j]);long long z=q(a[i][i],P-2);for(int j=0;j<2*n;j++)a[i][j]=a[i][j]*z%P;for(int r=0;r<n;r++)if(r!=i&&a[r][i]){z=a[r][i];for(int j=0;j<2*n;j++)a[r][j]=(a[r][j]-z*a[i][j]%P+P)%P;}}for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<(j?" ":"")<<a[i][j+n];cout<<'\\n';}}
'''
AB='''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;const int N=105;long long a[N][N],b[N][N+1],c[N][N];long long q(long long a,long long n){long long r=1;for(;n;n>>=1,a=a*a%P)if(n&1)r=r*a%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];for(int k=0;k<n;k++){for(int i=0;i<n;i++){for(int j=0;j<n;j++)b[i][j]=a[i][j];b[i][n]=i==k;}for(int i=0;i<n;i++){int r=i;while(r<n&&!b[r][i])r++;if(r==n)return cout<<"No Solution\\n",0;for(int j=i;j<=n;j++)swap(b[i][j],b[r][j]);long long z=q(b[i][i],P-2);for(int j=i;j<=n;j++)b[i][j]=b[i][j]*z%P;for(int x=0;x<n;x++)if(x!=i){z=b[x][i];for(int j=i;j<=n;j++)b[x][j]=(b[x][j]-z*b[i][j]%P+P)%P;}}for(int i=0;i<n;i++)c[i][k]=b[i][n];}for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<(j?" ":"")<<c[i][j];cout<<'\\n';}}
'''
AG='''#include <bits/stdc++.h>
using namespace std;const int N=405;long long a[N][N];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):10;mt19937_64 g(s);int n=g()%min(400ULL,max(1ULL,z))+1;cout<<n<<'\\n';for(int i=0;i<n;i++){for(int j=0;j<n;j++)a[i][j]=j<i?0:g()%1000000007;if(!a[i][i])a[i][i]=1;for(int j=0;j<n;j++)cout<<(j?" ":"")<<a[i][j];cout<<'\\n';}}
'''
AS='''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;long long a[9][18],o[9][9],z[9][9];long long q(long long a,long long n){long long r=1;for(;n;n>>=1,a=a*a%P)if(n&1)r=r*a%P;return r;}int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%8+1;memset(a,0,sizeof a);for(int i=0;i<n;i++){for(int j=0;j<n;j++)o[i][j]=a[i][j]=j<i?0:g()%1000+1;a[i][i+n]=1;}for(int i=0;i<n;i++){int k=i;while(k<n&&!a[k][i])k++;if(k==n)return cout<<"WA\\n",1;for(int j=0;j<2*n;j++)swap(a[i][j],a[k][j]);long long x=q(a[i][i],P-2);for(int j=0;j<2*n;j++)a[i][j]=a[i][j]*x%P;for(int r=0;r<n;r++)if(r!=i){x=a[r][i];for(int j=0;j<2*n;j++)a[r][j]=(a[r][j]-x*a[i][j]%P+P)%P;}}for(int i=0;i<n;i++)for(int j=0;j<n;j++){z[i][j]=0;for(int k=0;k<n;k++)z[i][j]=(z[i][j]+o[i][k]*a[k][j+n])%P;if(z[i][j]!=(i==j))return cout<<"WA\\n",1;}}cout<<"OK\\n";}
'''
add('P4783','P4783 【模板】矩阵求逆','把原矩阵与单位矩阵拼接，用模意义下的 Gauss-Jordan 消元把左半边化为单位矩阵，右半边即为逆矩阵。找不到非零主元时矩阵不可逆。时间复杂度 $O(N^3)$。',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},[A],[('1\n1\n','1\n'),('1\n0\n','No Solution\n'),('2\n2 0\n0 3\n','500000004 0\n0 333333336\n')])

B='''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;void f(unsigned long long n,long long&a,long long&b){if(!n){a=0;b=1;return;}long long c,d;f(n>>1,c,d);a=c*(2*d-c+P)%P;b=(c*c+d*d)%P;if(n&1){c=a;a=b;b=(c+b)%P;}}
int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long n;long long a,b;cin>>n;f(n,a,b);cout<<a<<'\\n';}
'''
BB='''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long n;cin>>n;long long a=0,b=1;while(n--){long long c=(a+b)%P;a=b;b=c;}cout<<a<<'\\n';}
'''
BG='''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);cout<<g()%max(1ULL,z)+1<<'\\n';}
'''
BS='''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;void f(unsigned long long n,long long&a,long long&b){if(!n){a=0;b=1;return;}long long c,d;f(n>>1,c,d);a=c*(2*d-c+P)%P;b=(c*c+d*d)%P;if(n&1){c=a;a=b;b=(c+b)%P;}}int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int r=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(r--){unsigned long long n=g()%1000+1;long long a,b,x=0,y=1;f(n,a,b);while(n--){long long z=(x+y)%P;x=y;y=z;}if(a!=x)return cout<<"WA\\n",1;}cout<<"OK\\n";}
'''
add('P1962','P1962 斐波那契数列','快速倍增同时计算 $(F_n,F_{n+1})$，利用二倍角恒等式递归折半下标。时间复杂度 $O(\\log n)$，递归深度 $O(\\log n)$。',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},[BB],[('1\n','1\n'),('2\n','1\n'),('93\n','720754435\n')])

C='''#include <bits/stdc++.h>
using namespace std;const int N=3e7+5;char s[N];unsigned long long M;unsigned long long q(unsigned long long a,unsigned long long b,unsigned long long m){return(__uint128_t)a*b%m;}unsigned long long p(unsigned long long a,unsigned long long n,unsigned long long m){unsigned long long r=1%m;for(;n;n>>=1,a=q(a,a,m))if(n&1)r=q(r,a,m);return r;}void f(unsigned long long n,unsigned long long m,unsigned long long&a,unsigned long long&b){if(!n){a=0;b=1%m;return;}unsigned long long c,d;f(n>>1,m,c,d);a=q(c,(2*d+m-c)%m,m);b=(q(c,c,m)+q(d,d,m))%m;if(n&1){c=a;a=b;b=(c+b)%m;}}bool t(unsigned long long n,unsigned long long m){unsigned long long a,b;f(n,m,a,b);return a==0&&b==1%m;}unsigned long long r(unsigned long long x){if(x==2)return 3;if(x==5)return 20;unsigned long long z=p(5,(x-1)/2,x)==1?x-1:2*(x+1),y=z;for(unsigned long long i=2;i*i<=y;i++)if(y%i==0){while(y%i==0)y/=i;while(z%i==0&&t(z/i,x))z/=i;}if(y>1)while(z%y==0&&t(z/y,x))z/=y;return z;}unsigned long long g(unsigned long long x,unsigned long long y){return x/__gcd(x,y)*y;}unsigned long long h(unsigned long long x){if(x==1)return 1;unsigned long long z=1;for(unsigned long long i=2;i*i<=x;i++)if(x%i==0){int e=0;while(x%i==0)x/=i,e++;unsigned long long v=r(i);while(--e)v*=i;z=g(z,v);}if(x>1)z=g(z,r(x));return z;}
int main(){ios::sync_with_stdio(0);cin.tie(0);cin>>s>>M;if(M==1)return cout<<0<<'\\n',0;unsigned long long z=h(M),n=0;for(int i=0;s[i];i++)n=((__uint128_t)n*10+s[i]-48)%z;unsigned long long a,b;f(n,M,a,b);cout<<a<<'\\n';}
'''
CB='''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long n,p,a=0,b=1;cin>>n>>p;while(n--){unsigned long long c=((__uint128_t)a+b)%p;a=b;b=c;}cout<<a%p<<'\\n';}
'''
CG='''#include <bits/stdc++.h>
using namespace std;const int N=1e6+5;char a[N];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);int n=min((unsigned long long)1e6,max(1ULL,z));a[0]=g()%9+49;for(int i=1;i<n;i++)a[i]=g()%10+48;a[n]=0;cout<<a<<'\\n'<<g()%2147483646+1<<'\\n';}
'''
CS='''#include <bits/stdc++.h>
using namespace std;unsigned long long q(unsigned long long a,unsigned long long b,unsigned long long m){return(__uint128_t)a*b%m;}unsigned long long k(unsigned long long a,unsigned long long n,unsigned long long m){unsigned long long r=1%m;for(;n;n>>=1,a=q(a,a,m))if(n&1)r=q(r,a,m);return r;}void f(unsigned long long n,unsigned long long m,unsigned long long&a,unsigned long long&b){if(!n){a=0;b=1%m;return;}unsigned long long c,d;f(n>>1,m,c,d);a=q(c,(2*d+m-c)%m,m);b=(q(c,c,m)+q(d,d,m))%m;if(n&1){c=a;a=b;b=(c+b)%m;}}bool t(unsigned long long n,unsigned long long m){unsigned long long a,b;f(n,m,a,b);return a==0&&b==1%m;}unsigned long long r(unsigned long long x){if(x==2)return 3;if(x==5)return 20;unsigned long long z=k(5,(x-1)/2,x)==1?x-1:2*(x+1),y=z;for(unsigned long long i=2;i*i<=y;i++)if(y%i==0){while(y%i==0)y/=i;while(z%i==0&&t(z/i,x))z/=i;}if(y>1)while(z%y==0&&t(z/y,x))z/=y;return z;}unsigned long long l(unsigned long long x,unsigned long long y){return x/__gcd(x,y)*y;}unsigned long long h(unsigned long long x){if(x==1)return 1;unsigned long long z=1;for(unsigned long long i=2;i*i<=x;i++)if(x%i==0){int e=0;while(x%i==0)x/=i,e++;unsigned long long v=r(i);while(--e)v*=i;z=l(z,v);}if(x>1)z=l(z,r(x));return z;}unsigned long long b(unsigned long long p){if(p==1)return 1;unsigned long long a=0,c=1%p,n=0;do{unsigned long long d=(a+c)%p;a=c;c=d;n++;}while(a||c!=1%p);return n;}int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int n=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(n--){unsigned long long p=g()%500+1;if(h(p)!=b(p))return cout<<"WA\\n",1;}cout<<"OK\\n";}
'''
add('P4000','P4000 斐波那契数列','先分解模数并求 Pisano 周期：质数周期从 $p-1$ 或 $2(p+1)$ 的因子中检验，质数幂与不同质因子的周期分别按乘法和最小公倍数组合。逐位读取超长下标并对周期取模，最后快速倍增。时间复杂度 $O(\\sqrt p+|n|+\\log p)$。',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},[],[('0\n7\n','0\n'),('10\n7\n','6\n'),('100000000000000000000\n2\n','1\n')])

D='''#include <bits/stdc++.h>
using namespace std;const int N=35;const long long P=2017;long long a[N][N],b[N][N],c[N][N];int n;void q(long long x[N][N],long long y[N][N]){memset(c,0,sizeof c);for(int i=0;i<=n;i++)for(int k=0;k<=n;k++)for(int j=0;j<=n;j++)c[i][j]=(c[i][j]+x[i][k]*y[k][j])%P;memcpy(x,c,sizeof c);}int main(){ios::sync_with_stdio(0);cin.tie(0);int m,t;cin>>n>>m;while(m--){int u,v;cin>>u>>v;u--;v--;a[u][v]=a[v][u]=1;}cin>>t;for(int i=0;i<=n;i++)a[i][i]=b[i][i]=1;for(int i=0;i<n;i++)a[i][n]=1;for(;t;t>>=1,q(a,a))if(t&1)q(b,a);long long r=0;for(int i=0;i<=n;i++)r=(r+b[0][i])%P;cout<<r<<'\\n';}
'''
DB='''#include <bits/stdc++.h>
using namespace std;const int N=35;const long long P=2017;long long a[N][N],f[N],g[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m,t;cin>>n>>m;while(m--){int u,v;cin>>u>>v;u--;v--;a[u][v]=a[v][u]=1;}cin>>t;for(int i=0;i<=n;i++)a[i][i]=1;for(int i=0;i<n;i++)a[i][n]=1;f[0]=1;while(t--){memset(g,0,sizeof g);for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)g[j]=(g[j]+f[i]*a[i][j])%P;memcpy(f,g,sizeof g);}long long r=0;for(int i=0;i<=n;i++)r=(r+f[i])%P;cout<<r<<'\\n';}
'''
DG='''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):10;mt19937_64 g(s);int n=g()%min(29ULL,max(1ULL,z-1))+2,m=n*(n-1)/2;cout<<n<<' '<<m<<'\\n';for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)cout<<i<<' '<<j<<'\\n';cout<<g()%max(2ULL,z)+2<<'\\n';}
'''
DS='''#include <bits/stdc++.h>
using namespace std;const long long P=2017;long long a[9][9],b[9][9],c[9][9],d[9][9],f[9],g[9];int n;void q(long long x[9][9],long long y[9][9]){memset(c,0,sizeof c);for(int i=0;i<=n;i++)for(int k=0;k<=n;k++)for(int j=0;j<=n;j++)c[i][j]=(c[i][j]+x[i][k]*y[k][j])%P;memcpy(x,c,sizeof c);}int main(int c0,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=c0>1?stoi(v[1]):1000;unsigned long long s=c0>2?stoull(v[2]):1;mt19937_64 h(s);while(R--){n=h()%7+1;int t=h()%20;memset(a,0,sizeof a);memset(b,0,sizeof b);for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(h()&1)a[i][j]=a[j][i]=1;for(int i=0;i<=n;i++)a[i][i]=b[i][i]=1;for(int i=0;i<n;i++)a[i][n]=1;memcpy(d,a,sizeof a);int z=t;for(;z;z>>=1,q(a,a))if(z&1)q(b,a);memset(f,0,sizeof f);f[0]=1;while(t--){memset(g,0,sizeof g);for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)g[j]=(g[j]+f[i]*d[i][j])%P;memcpy(f,g,sizeof g);}for(int j=0;j<=n;j++)if(b[0][j]!=f[j])return cout<<"WA\\n",1;}cout<<"OK\\n";}
'''
add('P3758','P3758 [TJOI2017] 可乐','增加一个“已自爆”吸收状态。城市状态可原地停留、沿边移动或转入自爆状态；对转移矩阵做 $t$ 次幂，从初始城市出发的各终态方案数之和即答案。时间复杂度 $O(N^3\\log t)$。',{'.cpp':D,' 数据生成.cpp':DG,' 暴力.cpp':DB,' 对拍.cpp':DS},[DB],[('2 1\n1 2\n1\n','3\n'),('2 1\n1 2\n2\n','7\n'),('3 3\n1 2\n2 3\n1 3\n1\n','4\n')])
