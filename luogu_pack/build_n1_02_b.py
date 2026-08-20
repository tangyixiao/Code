from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=105;const long long P=1e9+7;long long a[N][N],b[N][N],c[N][N];bool x[N],y[N];int n;void q(long long u[N][N],long long v[N][N]){memset(c,0,sizeof c);for(int i=0;i<n;i++)for(int k=0;k<n;k++)if(u[i][k])for(int j=0;j<n;j++)c[i][j]=(c[i][j]+u[i][k]*v[k][j])%P;memcpy(u,c,sizeof c);}int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long m;int u,v,z;cin>>m>>u;while(u--)cin>>z,x[z]=1;cin>>v;while(v--)cin>>z,y[z]=1;for(n=100;n&&!(x[n]&&y[n]);n--);if(!n)return cout<<0<<'\n',0;for(int j=1;j<=n;j++)if(x[j]&&y[j])a[0][j-1]=1;for(int i=1;i<n;i++)a[i][i-1]=1;for(int i=0;i<n;i++)b[i][i]=1;for(;m;m>>=1,q(a,a))if(m&1)q(b,a);cout<<b[0][0]<<'\n';}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;const int N=1e6+5;const long long P=1e9+7;long long f[N];bool a[105],b[105];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,x,z;cin>>n>>x;while(x--)cin>>z,a[z]=1;cin>>x;while(x--)cin>>z,b[z]=1;f[0]=1;for(int i=1;i<=n;i++)for(int j=1;j<=100&&j<=i;j++)if(a[j]&&b[j])f[i]=(f[i]+f[i-j])%P;cout<<f[n]<<'\n';}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;bool a[105],b[105];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int x=g()%min(100ULL,max(1ULL,z))+1,y=g()%min(100ULL,max(1ULL,z))+1;cout<<g()%max(1ULL,z)+1<<'\n'<<x<<'\n';while(x--){int q=g()%100+1;cout<<q<<' ';}cout<<'\n'<<y<<'\n';while(y--)cout<<g()%100+1<<' ';cout<<'\n';}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;long long f[205],a[105][105],b[105][105],c[105][105];bool x[105],y[105];int n;void q(long long u[105][105],long long v[105][105]){memset(c,0,sizeof c);for(int i=0;i<n;i++)for(int k=0;k<n;k++)for(int j=0;j<n;j++)c[i][j]=(c[i][j]+u[i][k]*v[k][j])%P;memcpy(u,c,sizeof c);}int main(int c0,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=c0>1?stoi(v[1]):1000;unsigned long long s=c0>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int m=g()%200+1;n=g()%10+1;memset(x,0,sizeof x);memset(y,0,sizeof y);memset(a,0,sizeof a);memset(b,0,sizeof b);memset(f,0,sizeof f);for(int i=1;i<=n;i++)x[i]=g()&1,y[i]=g()&1,a[0][i-1]=x[i]&&y[i];for(int i=1;i<n;i++)a[i][i-1]=1;for(int i=0;i<n;i++)b[i][i]=1;int z=m;for(;z;z>>=1,q(a,a))if(z&1)q(b,a);f[0]=1;for(int i=1;i<=m;i++)for(int j=1;j<=n&&j<=i;j++)if(x[j]&&y[j])f[i]=(f[i]+f[i-j])%P;if(b[0][0]!=f[m])return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P5343','P5343 【XR-1】分块',r'先取两人允许块长的交集。令 $f_i$ 为拼出长度 $i$ 的方案数，则 $f_i=\sum_{d\in S}f_{i-d}$。最大块长不超过 $100$，用伴随矩阵快速幂求 $f_n$。时间复杂度 $O(x^3\log n)$。',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},parts=[AB],extra=[('1\n1\n1\n1\n1\n','1\n'),('3\n2\n1 2\n2\n1 2\n','3\n'),('5\n1\n2\n1\n3\n','0\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;const int N=26;const long long P=1e9+7;long long a[N][N],b[N][N],c[N][N];bool f[N][N];char s[100005];void q(long long x[N][N],long long y[N][N]){memset(c,0,sizeof c);for(int i=0;i<N;i++)for(int k=0;k<N;k++)for(int j=0;j<N;j++)c[i][j]=(c[i][j]+x[i][k]*y[k][j])%P;memcpy(x,c,sizeof c);}int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long n;cin>>n>>s;for(int i=1;s[i];i++)f[s[i-1]-97][s[i]-97]=1;for(int i=0;i<N;i++)for(int j=0;j<N;j++)a[i][j]=!f[i][j],b[i][j]=i==j;for(n--;n;n>>=1,q(a,a))if(n&1)q(b,a);long long r=0;for(int i=0;i<N;i++)for(int j=0;j<N;j++)r=(r+b[i][j])%P;cout<<r<<'\n';}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;long long a[2][26];bool f[26][26];char s[100005];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n>>s;for(int i=1;s[i];i++)f[s[i-1]-97][s[i]-97]=1;for(int i=0;i<26;i++)a[1][i]=1;for(int k=2;k<=n;k++){memset(a[k&1],0,sizeof a[0]);for(int i=0;i<26;i++)for(int j=0;j<26;j++)if(!f[i][j])a[k&1][j]=(a[k&1][j]+a[k-1&1][i])%P;}long long r=0;for(int i=0;i<26;i++)r=(r+a[n&1][i])%P;cout<<r<<'\n';}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;char s[100005];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long z=c>1?stoull(v[1]):1,w=c>2?stoull(v[2]):20;mt19937_64 g(z);int n=g()%max(1ULL,w)+1,m=g()%min(100000ULL,max(1ULL,w))+1;cout<<n<<'\n';for(int i=0;i<m;i++)cout<<char(g()%26+97);cout<<'\n';}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;long long a[26][26],b[26][26],c[26][26],d[2][26];bool f[26][26];void q(long long x[26][26],long long y[26][26]){memset(c,0,sizeof c);for(int i=0;i<26;i++)for(int k=0;k<26;k++)for(int j=0;j<26;j++)c[i][j]=(c[i][j]+x[i][k]*y[k][j])%P;memcpy(x,c,sizeof c);}int main(int c0,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=c0>1?stoi(v[1]):1000;unsigned long long s=c0>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%100+1;memset(f,0,sizeof f);memset(a,0,sizeof a);memset(b,0,sizeof b);memset(d,0,sizeof d);for(int z=0;z<30;z++)f[g()%26][g()%26]=1;for(int i=0;i<26;i++)for(int j=0;j<26;j++)a[i][j]=!f[i][j],b[i][j]=i==j;int z=n-1;for(;z;z>>=1,q(a,a))if(z&1)q(b,a);long long x=0,y=0;for(int i=0;i<26;i++)d[1][i]=1;for(int k=2;k<=n;k++){memset(d[k&1],0,sizeof d[0]);for(int i=0;i<26;i++)for(int j=0;j<26;j++)if(!f[i][j])d[k&1][j]=(d[k&1][j]+d[k-1&1][i])%P;}for(int i=0;i<26;i++)for(int j=0;j<26;j++)x=(x+b[i][j])%P;for(int i=0;i<26;i++)y=(y+d[n&1][i])%P;if(x!=y)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P5337','P5337 [TJOI2019] 甲苯先生的字符串',r'把字母看成 $26$ 个状态，若有序对在原串中相邻出现，就禁止对应转移。合法长度为 $n$ 的字符串数是允许转移矩阵 $A^{n-1}$ 的所有元素之和。时间复杂度 $O(26^3\log n+|s_1|)$。',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},parts=[BB],extra=[('1\na\n','26\n'),('2\naa\n','675\n'),('3\nz\n','17576\n')])
