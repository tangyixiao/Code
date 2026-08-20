from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=3000005;long long a[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long p;cin>>n>>p;a[1]=1;cout<<1<<'\n';for(int i=2;i<=n;i++)a[i]=(p-p/i)*a[p%i]%p,cout<<a[i]<<'\n';}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;long long F(long long a,long long b,long long p){long long r=1;for(;b;b>>=1,a=a*a%p)if(b&1)r=r*a%p;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long p;cin>>n>>p;for(int i=1;i<=n;i++)cout<<F(i,p-2,p)<<'\n';}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);const int P=10000019;cout<<g()%min(3000000ULL,max(1ULL,z))+1<<' '<<P<<'\n';}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;const int N=10010,P=10007;long long a[N];long long F(long long x,int n=P-2){long long r=1;for(;n;n>>=1,x=x*x%P)if(n&1)r=r*x%P;return r;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%(P-1)+1;a[1]=1;for(int i=2;i<=n;i++)a[i]=1LL*(P-P/i)*a[P%i]%P;for(int i=1;i<=n;i++)if(a[i]!=F(i))return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P3811','P3811 【模板】模意义下的乘法逆元',r'设 $p=qi+r$，在模 $p$ 意义下有 $qi+r=0$，整理得 $i^{-1}=-(p/i)\,(p\bmod i)^{-1}$。从 $1$ 到 $n$ 递推即可在线性时间求出全部逆元。',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},parts=[AB],extra=[('1 2\n','1\n'),('3 7\n','1\n4\n5\n'),('5 11\n','1\n6\n4\n3\n9\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;long long F(long long a,long long b,long long p){long long r=1;for(;b;b>>=1,a=a*a%p)if(b&1)r=r*a%p;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long p,k,a,s=0,q=1,w;cin>>n>>p>>k;w=k;while(n--){cin>>a;s=(s*a+w*q)%p;q=q*a%p;w=w*k%p;}cout<<s*F(q,p-2,p)%p<<'\n';}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;long long F(long long a,long long b,long long p){long long r=1;for(;b;b>>=1,a=a*a%p)if(b&1)r=r*a%p;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long p,k,a,w,s=0;cin>>n>>p>>k;w=k;while(n--){cin>>a;s=(s+w*F(a,p-2,p))%p;w=w*k%p;}cout<<s<<'\n';}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);const int P=998244353;int n=g()%min(5000000ULL,max(1ULL,z))+1;cout<<n<<' '<<P<<' '<<g()%(P-2)+2<<'\n';while(n--)cout<<g()%(P-1)+1<<' ';cout<<'\n';}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;const int P=10007,N=55;int a[N];long long F(long long x,int n=P-2){long long r=1;for(;n;n>>=1,x=x*x%P)if(n&1)r=r*x%P;return r;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long S=C>2?stoull(v[2]):1;mt19937_64 g(S);while(R--){int n=g()%50+1,k=g()%(P-2)+2;long long s=0,q=1,w=k,t=0;for(int i=0;i<n;i++){a[i]=g()%(P-1)+1;s=(s*a[i]+w*q)%P;q=q*a[i]%P;t=(t+w*F(a[i]))%P;w=w*k%P;}s=s*F(q)%P;if(s!=t)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P5431','P5431 【模板】模意义下的乘法逆元 2',r'令 $Q_i=\prod_{j=1}^i a_j$，$S_i=\sum_{j=1}^i k^j\prod_{t\ne j,t\le i}a_t$。读入 $a_i$ 时递推 $S_i=a_iS_{i-1}+k^iQ_{i-1}$，最后所求为 $S_nQ_n^{-1}$，只需常数额外空间。',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},parts=[BB],extra=[('1 7 2\n3\n','3\n'),('2 7 2\n1 2\n','4\n'),('3 11 3\n2 4 5\n','2\n')])

E=r'''#include <bits/stdc++.h>
using namespace std;long long E(long long a,long long b,long long&x,long long&y){if(!b)return x=1,y=0,a;long long d=E(b,a%b,y,x);y-=a/b*x;return d;}
'''
C=E+r'''int main(){ios::sync_with_stdio(0);cin.tie(0);int n;long long m,r;cin>>n>>m>>r;r%=m;while(--n){long long a,b,x,y;cin>>a>>b;long long d=E(m,a,x,y),q=a/d,t=(long long)((__int128)(b-r)/d*x%q);r=(long long)(((__int128)r+(__int128)m*t)%(m*q));m*=q;if(r<0)r+=m;}cout<<r<<'\n';}
'''
CB=r'''#include <bits/stdc++.h>
using namespace std;const int N=12;long long a[N],b[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;long long m=1;for(int i=0;i<n;i++)cin>>a[i]>>b[i],m=m/__gcd(m,a[i])*a[i];for(long long x=0;x<m;x++){bool f=1;for(int i=0;i<n;i++)if(x%a[i]!=b[i]%a[i])f=0;if(f)return cout<<x<<'\n',0;}}
'''
CG=r'''#include <bits/stdc++.h>
using namespace std;const int a[16]={1,2,3,4,5,6,7,8,9,10,12,14,15,18,20,24};int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(100000ULL,max(1ULL,z))+1,x=g()%2520;cout<<n<<'\n';while(n--){int m=a[g()%16];cout<<m<<' '<<x%m<<'\n';}}
'''
CS=r'''#include <bits/stdc++.h>
using namespace std;long long E(long long a,long long b,long long&x,long long&y){if(!b)return x=1,y=0,a;long long d=E(b,a%b,y,x);y-=a/b*x;return d;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long S=C>2?stoull(v[2]):1;mt19937_64 g(S);while(R--){int n=g()%5+1;long long z=g()%100,m=1,r=0;for(int i=0;i<n;i++){long long a=g()%10+1,b=z%a,x,y,d=E(m,a,x,y),q=a/d,t=(__int128)(b-r)/d*x%q;r=((__int128)r+m*t)%(m*q);m*=q;if(r<0)r+=m;}long long x=0;while(x<m&&x!=z%m)x++;if(r!=x)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P4777','P4777 【模板】扩展中国剩余定理（EXCRT）',r'逐个合并同余式。已有 $x\equiv r\pmod m$，新式为 $x\equiv b\pmod a$，则需解 $mt\equiv b-r\pmod a$；扩展欧几里得求 $t$，更新模数为最小公倍数。乘法使用 `__int128` 防止中间溢出。',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},extra=[('1\n5 3\n','3\n'),('2\n4 2\n6 4\n','10\n'),('3\n6 5\n8 5\n9 5\n','5\n')])

D=E+r'''const int N=15;long long a[N],b[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>a[i];for(int i=0;i<n;i++)cin>>b[i];long long m=1,r=0;for(int i=0;i<n;i++){long long x,y,d=E(m,b[i],x,y),q=b[i]/d,t=(long long)((__int128)(a[i]-r)/d*x%q);r=(long long)(((__int128)r+(__int128)m*t)%(m*q));m*=q;if(r<0)r+=m;}cout<<r<<'\n';}
'''
DB=r'''#include <bits/stdc++.h>
using namespace std;const int N=12;long long a[N],b[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>a[i];long long m=1;for(int i=0;i<n;i++)cin>>b[i],m*=b[i];for(long long x=0;x<m;x++){bool f=1;for(int i=0;i<n;i++)if((x-a[i])%b[i])f=0;if(f)return cout<<x<<'\n',0;}}
'''
DG=r'''#include <bits/stdc++.h>
using namespace std;const int p[10]={2,3,5,7,11,13,17,19,23,29};int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):10;mt19937_64 g(s);int n=g()%min(10ULL,max(1ULL,z))+1;cout<<n<<'\n';for(int i=0;i<n;i++)cout<<(long long)(g()%2000000001)-1000000000<<' ';cout<<'\n';for(int i=0;i<n;i++)cout<<p[i]<<' ';cout<<'\n';}
'''
DS=r'''#include <bits/stdc++.h>
using namespace std;const int p[4]={2,3,5,7};long long E(long long a,long long b,long long&x,long long&y){if(!b)return x=1,y=0,a;long long d=E(b,a%b,y,x);y-=a/b*x;return d;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long S=C>2?stoull(v[2]):1;mt19937_64 g(S);while(R--){int n=g()%4+1;long long m=1,r=0,z=g()%210;for(int i=0;i<n;i++){long long a=z%p[i],x,y;E(m,p[i],x,y);long long t=(a-r)*x%p[i];r=(r+m*t)%(m*p[i]);m*=p[i];if(r<0)r+=m;}if(r!=z%m)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P3868','P3868 [TJOI2009] 猜数字',r'把条件写成 $n\equiv a_i\pmod{b_i}$，逐个用扩展 CRT 合并。题目保证模数两两互质，因此每次逆元存在；负余数在更新后归一化到当前模数范围。',{'.cpp':D,' 数据生成.cpp':DG,' 暴力.cpp':DB,' 对拍.cpp':DS},extra=[('1\n-1\n5\n','4\n'),('2\n2 3\n3 5\n','8\n'),('3\n-1 2 3\n2 3 5\n','23\n')])
