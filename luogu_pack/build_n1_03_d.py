from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=1200,B=1000000000;struct Q{int n,d[N];}a,b;void R(Q&x,string s){x.n=0;for(int i=s.size();i>0;i-=9){int l=max(0,i-9),v=0;for(int j=l;j<i;j++)v=v*10+s[j]-48;x.d[x.n++]=v;}}bool Z(Q&x){return x.n==1&&!x.d[0];}bool L(Q&x,Q&y){if(x.n!=y.n)return x.n<y.n;for(int i=x.n-1;i>=0;i--)if(x.d[i]!=y.d[i])return x.d[i]<y.d[i];return 0;}void H(Q&x){long long r=0;for(int i=x.n-1;i>=0;i--){long long v=x.d[i]+r*B;x.d[i]=v/2;r=v&1;}while(x.n>1&&!x.d[x.n-1])x.n--;}void S(Q&x,Q&y){long long r=0;for(int i=0;i<x.n;i++){long long v=(long long)x.d[i]-r-(i<y.n?y.d[i]:0);if(v<0)v+=B,r=1;else r=0;x.d[i]=v;}while(x.n>1&&!x.d[x.n-1])x.n--;}void M(Q&x,int y){long long r=0;for(int i=0;i<x.n;i++){long long v=(long long)x.d[i]*y+r;x.d[i]=v%B;r=v/B;}if(r)x.d[x.n++]=r;}int main(){ios::sync_with_stdio(0);cin.tie(0);string s;cin>>s;R(a,s);cin>>s;R(b,s);Q*x=&a,*y=&b;int k=0;while(!(x->d[0]&1)&&!(y->d[0]&1))H(*x),H(*y),k++;while(!(x->d[0]&1))H(*x);while(!Z(*y)){while(!(y->d[0]&1))H(*y);if(L(*y,*x))swap(x,y);S(*y,*x);}while(k){int t=min(k,29);M(*x,1<<t);k-=t;}cout<<x->d[x->n-1];for(int i=x->n-2;i>=0;i--)cout<<setw(9)<<setfill('0')<<x->d[i];cout<<'\n';}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long a,b;cin>>a>>b;while(b){a%=b;swap(a,b);}cout<<a<<'\n';}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);int n=min(10000ULL,max(1ULL,z));for(int k=0;k<2;k++){cout<<g()%9+1;for(int i=1;i<n;i++)cout<<g()%10;cout<<'\n';}}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;unsigned long long G(unsigned long long a,unsigned long long b){int k=0;while(!(a&1)&&!(b&1))a>>=1,b>>=1,k++;while(!(a&1))a>>=1;while(b){while(!(b&1))b>>=1;if(a>b)swap(a,b);b-=a;}return a<<k;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){unsigned long long a=g()|1,b=g()|1;if(G(a,b)!=__gcd(a,b))return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P2152','P2152 [SDOI2009] SuperGCD',r'用 $10^9$ 进制静态数组保存大整数，执行 Stein 二进制 GCD：提取公共的二因子，反复除二、比较和相减，最后乘回公共因子。所有运算都只扫描有效数位。',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},parts=[AB],extra=[('1\n1\n','1\n'),('12345678901234567890\n9876543210\n','90\n'),('1000000000000000000000000000000\n250000000000000000000000000000\n','250000000000000000000000000000\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;const int N=1005,L=11;int a[N][L];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i][0];for(int j=1;j<L;j++)for(int i=1;i+(1<<j)-1<=n;i++)a[i][j]=__gcd(a[i][j-1],a[i+(1<<j-1)][j-1]);while(m--){int l,r;cin>>l>>r;int k=31-__builtin_clz(r-l+1);cout<<__gcd(a[l][k],a[r-(1<<k)+1][k])<<'\n';}}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;const int N=1005;int a[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];while(m--){int l,r,z=0;cin>>l>>r;for(int i=l;i<=r;i++)z=__gcd(z,a[i]);cout<<z<<'\n';}}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(1000ULL,max(1ULL,z))+1,m=g()%min(1000000ULL,max(1ULL,z*z))+1;cout<<n<<' '<<m<<'\n';for(int i=0;i<n;i++)cout<<g()%1000000000+1<<' ';cout<<'\n';while(m--){int l=g()%n+1,r=g()%n+1;if(l>r)swap(l,r);cout<<l<<' '<<r<<'\n';}}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;const int N=105,L=8;int a[N],b[N][L];int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%100+1;for(int i=1;i<=n;i++)a[i]=b[i][0]=g()%10000+1;for(int j=1;j<L;j++)for(int i=1;i+(1<<j)-1<=n;i++)b[i][j]=__gcd(b[i][j-1],b[i+(1<<j-1)][j-1]);for(int q=0;q<100;q++){int l=g()%n+1,r=g()%n+1;if(l>r)swap(l,r);int z=0;for(int i=l;i<=r;i++)z=__gcd(z,a[i]);int k=31-__builtin_clz(r-l+1);if(z!=__gcd(b[l][k],b[r-(1<<k)+1][k]))return cout<<"WA\n",1;}}cout<<"OK\n";}
'''
add('P1890','P1890 gcd 区间',r'最大公因数满足结合律和幂等性。预处理稀疏表，询问时取两个长度为 $2^k$、共同覆盖区间的块求 gcd。预处理 $O(n\log n)$，每次询问 $O(1)$。',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},parts=[BB],extra=[('1 3\n12\n1 1\n1 1\n1 1\n','12\n12\n12\n'),('5 3\n6 10 15 21 14\n1 3\n2 5\n4 5\n','1\n1\n7\n'),('4 2\n8 16 24 32\n2 3\n1 4\n','8\n8\n')])

C=r'''#include <bits/stdc++.h>
using namespace std;const int N=5005,V=1000005,P=998244353;int a[N],b[N],s[V],q[V],A[N][8],B[N][8],C[N][8],D[N][8],x[N],y[N],k;void F(int v,int p[8],int q[8],int&n){while(v>1){int z=s[v],w=1;while(s[v]==z)w*=z,v/=z;p[n]=z;q[n++]=w;}}int G(int i,int j){int u=0,v=0,r=1;while(u<x[i]&&v<y[j])if(A[i][u]==C[j][v])r*=min(B[i][u++],D[j][v++]);else if(A[i][u]<C[j][v])u++;else v++;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=2;i<V;i++){if(!s[i])s[i]=i,q[k++]=i;for(int j=0;j<k&&q[j]<=s[i]&&1LL*i*q[j]<V;j++)s[i*q[j]]=q[j];}for(int i=1;i<=n;i++)cin>>a[i],F(a[i],A[i],B[i],x[i]);for(int i=1;i<=n;i++)cin>>b[i],F(b[i],C[i],D[i],y[i]);for(int i=1;i<=n;i++){unsigned long long z=0,p=i;for(int j=1;j<=n;j++)z+=p*G(i,j),p=p*i%P;cout<<z%P<<'\n';}}
'''
CB=r'''#include <bits/stdc++.h>
using namespace std;const int N=5005,P=998244353;int a[N],b[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=1;i<=n;i++)cin>>a[i];for(int i=1;i<=n;i++)cin>>b[i];for(int i=1;i<=n;i++){long long s=0,p=i;for(int j=1;j<=n;j++)s=(s+p*__gcd(a[i],b[j]))%P,p=p*i%P;cout<<s<<'\n';}}
'''
CG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(5000ULL,max(1ULL,z))+1;cout<<n<<'\n';for(int k=0;k<2;k++){for(int i=0;i<n;i++)cout<<g()%1000000+1<<' ';cout<<'\n';}}
'''
CS=r'''#include <bits/stdc++.h>
using namespace std;const int V=1000005;int s[V],q[V],a[8],b[8],c[8],d[8],k;int F(int v,int*p,int*q){int n=0;while(v>1){int z=s[v],w=1;while(s[v]==z)w*=z,v/=z;p[n]=z;q[n++]=w;}return n;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long S=C>2?stoull(v[2]):1;mt19937_64 g(S);for(int i=2;i<V;i++){if(!s[i])s[i]=i,q[k++]=i;for(int j=0;j<k&&q[j]<=s[i]&&1LL*i*q[j]<V;j++)s[i*q[j]]=q[j];}while(R--)for(int z=0;z<100;z++){int x=g()%1000000+1,y=g()%1000000+1,A=F(x,a,b),B=F(y,c,d),i=0,j=0,r=1;while(i<A&&j<B)if(a[i]==c[j])r*=min(b[i++],d[j++]);else if(a[i]<c[j])i++;else j++;if(r!=__gcd(x,y))return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P5435','P5435 基于值域预处理的快速 GCD',r'先用最小质因子筛把每个输入数分解成按质数递增的质因子幂列表。求一对数的 gcd 时双指针合并两个短列表，相同质数取较小幂；核心的 $n^2$ 次计算不再执行取模。枚举 $j$ 时同步维护 $i^j$。',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},parts=[CB],extra=[('1\n6\n4\n','2\n'),('2\n2 3\n4 6\n','4\n14\n'),('2\n5 10\n10 15\n','10\n40\n')])

D=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int T;long long n;cin>>T;while(T--){cin>>n;cout<<(n==1?1:n*(n-1))<<'\n';}}
'''
DB=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int T,n;cin>>T;while(T--){cin>>n;long long r=1;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)r=max(r,1LL*i/__gcd(i,j)*j);cout<<r<<'\n';}}
'''
DG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);int T=g()%min(100ULL,max(1ULL,z))+1;cout<<T<<'\n';while(T--)cout<<g()%1000000000+1<<'\n';}
'''
DS=r'''#include <bits/stdc++.h>
using namespace std;int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%100+1;long long a=n==1?1:1LL*n*(n-1),b=1;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)b=max(b,1LL*i/__gcd(i,j)*j);if(a!=b)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P5436','P5436 【XR-2】缘分',r'两个数不超过 $n$ 时，它们的最小公倍数不超过乘积；两个不同的数的乘积至多为 $n(n-1)$。相邻整数 $n$ 与 $n-1$ 互质，恰好达到该上界。$n=1$ 时答案为 $1$。',{'.cpp':D,' 数据生成.cpp':DG,' 暴力.cpp':DB,' 对拍.cpp':DS},parts=[DB],extra=[('1\n1\n','1\n'),('3\n2\n4\n10\n','2\n12\n90\n'),('2\n100\n1000000000\n','9900\n999999999000000000\n')])
