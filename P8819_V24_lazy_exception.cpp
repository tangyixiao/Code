#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;

namespace TANGYIXIAO {
    const int N=5e5+5;
    const int B=224;
    const int HK=127;
    const int CMAX=127;
    const int DN_CAP=32<<20;
    const int SP_CAP=(32<<20)/4;
    const int IB=1<<20;

    struct FastIO {
        char ib[IB];
        int p,n;
        char out[4*N];
        int op;

        FastIO():p(0),n(0),op(0) {}

        inline char gc() {
            if (p==n) {
                n=fread(ib,1,IB,stdin);
                p=0;
            }
            return ib[p++];
        }

        inline int read() {
            char c=gc();
            for (;c<'0'||c>'9';c=gc()) {}

            int x=0;
            for (;c>='0'&&c<='9';c=gc()) {
                x=x*10+c-'0';
            }

            return x;
        }

        inline void yesno(bool ok) {
            if (ok) {
                out[op++]='Y';
                out[op++]='E';
                out[op++]='S';
                out[op++]='\n';
            } else {
                out[op++]='N';
                out[op++]='O';
                out[op++]='\n';
            }
        }

        inline void flush() {
            fwrite(out,1,op,stdout);
        }
    } io;

    uint64_t se[N],sq[N],rs[N];
    int rcnt[1<<13];

    int n,m,q,H,K,W,UW,IW,BW,RW,D,C,CW;

    int eu[N],ev[N],ind[N],outd[N];
    int beg[N],pos[N],src[N],obeg[N];

    int id[N],hc[N],hb[N],hp[N],uid[N];
    uint16_t hl[N];

    int val[N];

    alignas(64) int hs[N],hcur[N];

    int head[N],ec;
    uint64_t el[N];

    uint32_t qop[N];
    int qcnt[N],ord[N],hv[N];

    int typ[N],off[N],len[N],cid[N],cv[N];

    unsigned char ex[N],base[N];

    int *hh;

    unsigned char *tag;
    unsigned char *umask;
    uint64_t *tbit;
    uint64_t *ubit;
    unsigned char *dpool;
    unsigned char *ctran;
    int *cdot;
    unsigned char *ccnt;

    uint32_t *spool;

    int dused,sused,tmp[N];

    long long E,P;

    template <class T>
    T *alloc64(size_t cnt,bool zero=false) {
        size_t sz=cnt*sizeof(T);
        sz=(sz+63)&~63ULL;

        void *p=aligned_alloc(64,sz?sz:64);

        if (!p) {
            exit(0);
        }

        if (zero) {
            memset(p,0,sz);
        }

        return (T*)p;
    }

    __attribute__((target("avx2,bmi,bmi2,popcnt,lzcnt")))
    int fuse_u8_hot(
        int *a,
        const unsigned char *b,
        const unsigned char *t,
        int d
    ) {
        __m256i sm=_mm256_setzero_si256();
        const __m256i one=_mm256_set1_epi16(1);

        for (int i=0;i<W;i+=32) {
            __m256i bv=_mm256_load_si256(
                (const __m256i*)(b+i)
            );

            __m256i tv=_mm256_load_si256(
                (const __m256i*)(t+i)
            );

            __m256i z=_mm256_maddubs_epi16(
                bv,tv
            );

            sm=_mm256_add_epi32(
                sm,
                _mm256_madd_epi16(z,one)
            );

            if (i<UW) {
                __m128i x0=_mm_loadl_epi64(
                    (const __m128i*)(b+i)
                );

                __m128i x1=_mm_loadl_epi64(
                    (const __m128i*)(b+i+8)
                );

                __m128i x2=_mm_loadl_epi64(
                    (const __m128i*)(b+i+16)
                );

                __m128i x3=_mm_loadl_epi64(
                    (const __m128i*)(b+i+24)
                );

                __m256i y0=_mm256_cvtepu8_epi32(x0);
                __m256i y1=_mm256_cvtepu8_epi32(x1);
                __m256i y2=_mm256_cvtepu8_epi32(x2);
                __m256i y3=_mm256_cvtepu8_epi32(x3);

                __m256i a0=_mm256_load_si256(
                    (const __m256i*)(a+i)
                );

                __m256i a1=_mm256_load_si256(
                    (const __m256i*)(a+i+8)
                );

                __m256i a2=_mm256_load_si256(
                    (const __m256i*)(a+i+16)
                );

                __m256i a3=_mm256_load_si256(
                    (const __m256i*)(a+i+24)
                );

                if (d==1) {
                    a0=_mm256_add_epi32(a0,y0);
                    a1=_mm256_add_epi32(a1,y1);
                    a2=_mm256_add_epi32(a2,y2);
                    a3=_mm256_add_epi32(a3,y3);
                } else {
                    a0=_mm256_sub_epi32(a0,y0);
                    a1=_mm256_sub_epi32(a1,y1);
                    a2=_mm256_sub_epi32(a2,y2);
                    a3=_mm256_sub_epi32(a3,y3);
                }

                _mm256_store_si256(
                    (__m256i*)(a+i),a0
                );

                _mm256_store_si256(
                    (__m256i*)(a+i+8),a1
                );

                _mm256_store_si256(
                    (__m256i*)(a+i+16),a2
                );

                _mm256_store_si256(
                    (__m256i*)(a+i+24),a3
                );
            }
        }

        alignas(32) int s[8];

        _mm256_store_si256(
            (__m256i*)s,
            sm
        );

        return
            s[0]+s[1]+s[2]+s[3]+
            s[4]+s[5]+s[6]+s[7];
    }

    __attribute__((target("avx2,bmi,bmi2,popcnt,lzcnt")))
    void add_u8_i32_hot(
        int *a,
        const unsigned char *b,
        int d
    ) {
        for (int i=0;i<UW;i+=32) {
            __m128i x0=_mm_loadl_epi64(
                (const __m128i*)(b+i)
            );

            __m128i x1=_mm_loadl_epi64(
                (const __m128i*)(b+i+8)
            );

            __m128i x2=_mm_loadl_epi64(
                (const __m128i*)(b+i+16)
            );

            __m128i x3=_mm_loadl_epi64(
                (const __m128i*)(b+i+24)
            );

            __m256i y0=_mm256_cvtepu8_epi32(x0);
            __m256i y1=_mm256_cvtepu8_epi32(x1);
            __m256i y2=_mm256_cvtepu8_epi32(x2);
            __m256i y3=_mm256_cvtepu8_epi32(x3);

            __m256i a0=_mm256_load_si256(
                (const __m256i*)(a+i)
            );

            __m256i a1=_mm256_load_si256(
                (const __m256i*)(a+i+8)
            );

            __m256i a2=_mm256_load_si256(
                (const __m256i*)(a+i+16)
            );

            __m256i a3=_mm256_load_si256(
                (const __m256i*)(a+i+24)
            );

            if (d==1) {
                a0=_mm256_add_epi32(a0,y0);
                a1=_mm256_add_epi32(a1,y1);
                a2=_mm256_add_epi32(a2,y2);
                a3=_mm256_add_epi32(a3,y3);
            } else {
                a0=_mm256_sub_epi32(a0,y0);
                a1=_mm256_sub_epi32(a1,y1);
                a2=_mm256_sub_epi32(a2,y2);
                a3=_mm256_sub_epi32(a3,y3);
            }

            _mm256_store_si256(
                (__m256i*)(a+i),a0
            );

            _mm256_store_si256(
                (__m256i*)(a+i+8),a1
            );

            _mm256_store_si256(
                (__m256i*)(a+i+16),a2
            );

            _mm256_store_si256(
                (__m256i*)(a+i+24),a3
            );
        }
    }

    __attribute__((target("avx2,bmi,bmi2,popcnt,lzcnt")))
    void add_cache_i32(
        int *a,
        const unsigned char *b,
        int d
    ) {
        for (int i=0;i<CW;i+=32) {
            __m128i x0=_mm_loadl_epi64(
                (const __m128i*)(b+i)
            );

            __m128i x1=_mm_loadl_epi64(
                (const __m128i*)(b+i+8)
            );

            __m128i x2=_mm_loadl_epi64(
                (const __m128i*)(b+i+16)
            );

            __m128i x3=_mm_loadl_epi64(
                (const __m128i*)(b+i+24)
            );

            __m256i y0=_mm256_cvtepu8_epi32(x0);
            __m256i y1=_mm256_cvtepu8_epi32(x1);
            __m256i y2=_mm256_cvtepu8_epi32(x2);
            __m256i y3=_mm256_cvtepu8_epi32(x3);

            __m256i a0=_mm256_load_si256(
                (const __m256i*)(a+i)
            );

            __m256i a1=_mm256_load_si256(
                (const __m256i*)(a+i+8)
            );

            __m256i a2=_mm256_load_si256(
                (const __m256i*)(a+i+16)
            );

            __m256i a3=_mm256_load_si256(
                (const __m256i*)(a+i+24)
            );

            if (d==1) {
                a0=_mm256_add_epi32(a0,y0);
                a1=_mm256_add_epi32(a1,y1);
                a2=_mm256_add_epi32(a2,y2);
                a3=_mm256_add_epi32(a3,y3);
            } else {
                a0=_mm256_sub_epi32(a0,y0);
                a1=_mm256_sub_epi32(a1,y1);
                a2=_mm256_sub_epi32(a2,y2);
                a3=_mm256_sub_epi32(a3,y3);
            }

            _mm256_store_si256(
                (__m256i*)(a+i),a0
            );

            _mm256_store_si256(
                (__m256i*)(a+i+8),a1
            );

            _mm256_store_si256(
                (__m256i*)(a+i+16),a2
            );

            _mm256_store_si256(
                (__m256i*)(a+i+24),a3
            );
        }
    }

    __attribute__((target("popcnt")))
    int bit_sum(
        const uint64_t *a
    ) {
        int s=0;
        int i=0;

        for (;i+3<BW;i+=4) {
            s+=__builtin_popcountll(a[i]&tbit[i]);
            s+=__builtin_popcountll(a[i+1]&tbit[i+1]);
            s+=__builtin_popcountll(a[i+2]&tbit[i+2]);
            s+=__builtin_popcountll(a[i+3]&tbit[i+3]);
        }

        for (;i<BW;i++) {
            s+=__builtin_popcountll(a[i]&tbit[i]);
        }

        return s;
    }

    __attribute__((target("avx2,bmi,bmi2,popcnt,lzcnt")))
    void add_u8_i32(
        int *a,
        const unsigned char *b,
        int d
    ) {
        for (int i=0;i<W;i+=32) {
            __m128i x0=_mm_loadl_epi64(
                (const __m128i*)(b+i)
            );

            __m128i x1=_mm_loadl_epi64(
                (const __m128i*)(b+i+8)
            );

            __m128i x2=_mm_loadl_epi64(
                (const __m128i*)(b+i+16)
            );

            __m128i x3=_mm_loadl_epi64(
                (const __m128i*)(b+i+24)
            );

            __m256i y0=_mm256_cvtepu8_epi32(x0);
            __m256i y1=_mm256_cvtepu8_epi32(x1);
            __m256i y2=_mm256_cvtepu8_epi32(x2);
            __m256i y3=_mm256_cvtepu8_epi32(x3);

            __m256i a0=_mm256_load_si256(
                (const __m256i*)(a+i)
            );

            __m256i a1=_mm256_load_si256(
                (const __m256i*)(a+i+8)
            );

            __m256i a2=_mm256_load_si256(
                (const __m256i*)(a+i+16)
            );

            __m256i a3=_mm256_load_si256(
                (const __m256i*)(a+i+24)
            );

            if (d==1) {
                a0=_mm256_add_epi32(a0,y0);
                a1=_mm256_add_epi32(a1,y1);
                a2=_mm256_add_epi32(a2,y2);
                a3=_mm256_add_epi32(a3,y3);
            } else {
                a0=_mm256_sub_epi32(a0,y0);
                a1=_mm256_sub_epi32(a1,y1);
                a2=_mm256_sub_epi32(a2,y2);
                a3=_mm256_sub_epi32(a3,y3);
            }

            _mm256_store_si256(
                (__m256i*)(a+i),a0
            );

            _mm256_store_si256(
                (__m256i*)(a+i+8),a1
            );

            _mm256_store_si256(
                (__m256i*)(a+i+16),a2
            );

            _mm256_store_si256(
                (__m256i*)(a+i+24),a3
            );
        }
    }

    __attribute__((target("avx2,bmi,bmi2,popcnt,lzcnt")))
    void add_i32_hot(
        int *a,
        const int *b,
        int d
    ) {
        for (int i=0;i<IW;i+=8) {
            __m256i x=_mm256_load_si256(
                (const __m256i*)(a+i)
            );

            __m256i y=_mm256_load_si256(
                (const __m256i*)(b+i)
            );

            if (d==1) {
                x=_mm256_add_epi32(x,y);
            } else {
                x=_mm256_sub_epi32(x,y);
            }

            _mm256_store_si256(
                (__m256i*)(a+i),x
            );
        }
    }

    __attribute__((target("avx2,bmi,bmi2,popcnt,lzcnt")))
    int dot_i32_u8(
        const int *a,
        const unsigned char *b
    ) {
        __m256i sm=_mm256_setzero_si256();

        for (int i=0;i<W;i+=8) {
            __m256i x=_mm256_load_si256(
                (const __m256i*)(a+i)
            );

            __m128i yb=_mm_loadl_epi64(
                (const __m128i*)(b+i)
            );

            __m256i y=_mm256_cvtepu8_epi32(yb);

            sm=_mm256_add_epi32(
                sm,
                _mm256_mullo_epi32(x,y)
            );
        }

        alignas(32) int s[8];

        _mm256_store_si256(
            (__m256i*)s,
            sm
        );

        return
            s[0]+s[1]+s[2]+s[3]+
            s[4]+s[5]+s[6]+s[7];
    }

    inline void radix_sort(uint64_t *a,int z) {
        const int M=(1<<13)-1;
        uint64_t *x=a,*y=rs;

        for (int sh=20;sh<=46;sh+=13) {
            memset(rcnt,0,sizeof(rcnt));

            for (int i=1;i<=z;i++) {
                rcnt[(x[i]>>sh)&M]++;
            }

            int s=1;

            for (int i=0;i<=M;i++) {
                int c=rcnt[i];
                rcnt[i]=s;
                s+=c;
            }

            for (int i=1;i<=z;i++) {
                int d=(x[i]>>sh)&M;
                y[rcnt[d]++]=x[i];
            }

            swap(x,y);
        }

        if (x!=a) {
            memcpy(a+1,x+1,1LL*z*sizeof(uint64_t));
        }
    }

    inline void add_ex(int e,int v) {
        ex[e]=1;
        el[++ec]=(1ULL*head[v]<<20)|(unsigned int)e;
        head[v]=ec;
    }

    inline void point_add(int u,int d) {
        if (!d) {
            return;
        }

        int x=val[u];

        if (uid[u]) {
            x+=bit_sum(
                ubit+1LL*uid[u]*RW
            );

            add_u8_i32_hot(
                hs,
                umask+1LL*uid[u]*W,
                d
            );
        } else {
            for (int p=hb[u];p<hb[u+1];p++) {
                int h=hl[p];

                x+=tag[h];

                if (h<=K) {
                    hs[h]+=d;
                }
            }
        }

        if (d==1) {
            P+=x;
        } else {
            P-=x-1;
        }

        E+=d;
        val[u]+=d;
    }

    inline void light_add(int v,int d) {
        long long s=0;

        for (int p=beg[v];p<beg[v+1];p++) {
            int u=src[p];

            s+=val[u];
            val[u]+=d;
        }

        if (typ[v]==1) {
            uint32_t *a=
                spool+off[v];

            for (int i=0;i<len[v];i++) {
                uint32_t x=a[i];

                int h=x>>8;
                int c=x&255;

                s+=tag[h]*c;

                if (h<=K) {
                    hs[h]+=d*c;
                }
            }
        } else if (typ[v]==2) {
            if (cid[v]) {
                s+=cdot[cid[v]];

                add_u8_i32_hot(
                    hs,
                    dpool+off[v],
                    d
                );
            } else {
                s+=fuse_u8_hot(
                    hs,
                    dpool+off[v],
                    tag,
                    d
                );
            }
        } else if (typ[v]==3) {
            for (int p=beg[v];p<beg[v+1];p++) {
                int u=src[p];

                if (uid[u]) {
                    s+=bit_sum(
                        ubit+1LL*uid[u]*RW
                    );

                    add_u8_i32_hot(
                        hs,
                        umask+1LL*uid[u]*W,
                        d
                    );
                } else {
                    for (int z=hb[u];z<hb[u+1];z++) {
                        int h=hl[z];

                        s+=tag[h];

                        if (h<=K) {
                            hs[h]+=d;
                        }
                    }
                }
            }
        }

        if (d==1) {
            P+=s;
        } else {
            P+=ind[v]-s;
        }

        E+=1LL*d*ind[v];
    }

    inline void heavy_add(int v,int d) {
        int h=id[v];

        long long s=0;

        if (h<=K) {
            s=hs[h]+hcur[h];
        } else {
            for (int p=beg[v];p<beg[v+1];p++) {
                s+=val[src[p]];
            }

            s+=dot_i32_u8(
                hh+1LL*h*W,
                tag
            );
        }

        if (d==1) {
            P+=s;
        } else {
            P+=ind[v]-s;
        }

        E+=1LL*d*ind[v];

        tag[h]+=d;

        uint64_t z=1ULL<<(h&63);

        if (d==1) {
            tbit[h>>6]|=z;
        } else {
            tbit[h>>6]&=~z;
        }

        add_i32_hot(
            hcur,
            hh+1LL*h*W,
            d
        );

        if (C) {
            add_cache_i32(
                cdot,
                ctran+1LL*h*CW,
                d
            );
        }
    }

    inline void set_add(int v,int d) {
        if (id[v]) {
            heavy_add(v,d);
        } else {
            light_add(v,d);
        }
    }

    inline void clear_ex(int v) {
        const uint64_t M=(1ULL<<20)-1;
        int d=base[v]?1:-1;
        int p=head[v];

        head[v]=0;

        for (;p;) {
            uint64_t x=el[p];
            int e=x&M;
            p=x>>20;

            if (!ex[e]) {
                continue;
            }

            point_add(
                eu[e],
                d
            );

            ex[e]=0;
        }
    }

    inline void single_set(
        int e,
        int tar
    ) {
        int u=eu[e];
        int v=ev[e];
        int ne=tar^base[v];

        if (ex[e]==ne) {
            return;
        }

        point_add(
            u,
            tar?1:-1
        );

        if (ne) {
            add_ex(e,v);
        } else {
            ex[e]=0;
        }
    }

    inline void all_set(
        int v,
        int tar
    ) {
        clear_ex(v);

        if (base[v]!=tar) {
            set_add(
                v,
                tar-base[v]
            );

            base[v]=tar;
        }
    }

    void build() {
        H=0;

        for (int v=1;v<=n;v++) {
            if (ind[v]>B) {
                hv[++H]=v;
            }
        }

        sort(
            hv+1,
            hv+H+1,
            [&](int x,int y) {
                long long sx=
                    1LL*qcnt[x]*(ind[x]+1);

                long long sy=
                    1LL*qcnt[y]*(ind[y]+1);

                if (sx!=sy) {
                    return sx>sy;
                }

                return ind[x]>ind[y];
            }
        );

        K=min(H,HK);

        for (
            ;
            K&&qcnt[hv[K]]==0;
            K--
        ) {}

        for (int h=1;h<=H;h++) {
            id[hv[h]]=h;
        }

        for (int v=1;v<=n;v++) {
            base[v]=1;
        }

        W=((H+1+63)>>6)<<6;

        if (!W) {
            W=64;
        }

        BW=(H+64)>>6;
        RW=(BW+7)&~7;

        if (!RW) {
            RW=8;
        }

        UW=((K+1+31)>>5)<<5;
        IW=((K+1+7)>>3)<<3;

        if (!UW) {
            UW=32;
        }

        if (!IW) {
            IW=8;
        }

        if (UW>W) {
            UW=W;
        }

        if (IW>W) {
            IW=W;
        }

        for (int i=1;i<=m;i++) {
            int u=eu[i];
            int v=ev[i];

            if (id[v]) {
                hc[u]++;
            } else {
                val[u]++;
            }
        }

        hb[1]=1;

        for (int u=1;u<=n;u++) {
            hb[u+1]=hb[u]+hc[u];
            hp[u]=hb[u];
        }

        for (int i=1;i<=m;i++) {
            int h=id[ev[i]];

            if (h) {
                hl[hp[eu[i]]++]=(uint16_t)h;
            }
        }

        int T=max(8,H/8);

        D=0;

        for (int u=1;u<=n;u++) {
            if (hc[u]>T) {
                uid[u]=++D;
            }
        }

        umask=alloc64<unsigned char>(
            1LL*(D+1)*W,
            true
        );

        ubit=alloc64<uint64_t>(
            1LL*(D+1)*RW,
            true
        );

        for (int u=1;u<=n;u++) {
            if (!uid[u]) {
                continue;
            }

            unsigned char *a=
                umask+1LL*uid[u]*W;

            uint64_t *b=
                ubit+1LL*uid[u]*RW;

            for (int p=hb[u];p<hb[u+1];p++) {
                int h=hl[p];

                a[h]=1;
                b[h>>6]|=1ULL<<(h&63);
            }
        }

        hh=alloc64<int>(
            1LL*(H+1)*W,
            true
        );

        tag=alloc64<unsigned char>(
            W,
            true
        );

        tbit=alloc64<uint64_t>(
            RW,
            true
        );

        for (int h=1;h<=H;h++) {
            tag[h]=1;
            tbit[h>>6]|=1ULL<<(h&63);
        }

        for (int i=1;i<=m;i++) {
            int h=id[ev[i]];

            if (h&&h<=K) {
                hs[h]+=val[eu[i]];
            }
        }

        for (int u=1;u<=n;u++) {
            if (!hc[u]) {
                continue;
            }

            if (uid[u]) {
                unsigned char *a=
                    umask+1LL*uid[u]*W;

                for (int p=hb[u];p<hb[u+1];p++) {
                    add_u8_i32(
                        hh+1LL*hl[p]*W,
                        a,
                        1
                    );
                }
            } else {
                for (int p=hb[u];p<hb[u+1];p++) {
                    int *a=
                        hh+1LL*hl[p]*W;

                    for (
                        int z=hb[u];
                        z<hb[u+1];
                        z++
                    ) {
                        a[hl[z]]++;
                    }
                }
            }
        }

        for (int i=1;i<=m;i++) {
            int h=id[ev[i]];

            if (h&&h<=K) {
                hcur[h]+=hc[eu[i]];
            }
        }

        dpool=alloc64<unsigned char>(
            DN_CAP,
            false
        );

        spool=alloc64<uint32_t>(
            SP_CAP,
            false
        );

        ccnt=alloc64<unsigned char>(
            W,
            true
        );

        int oc=0;

        for (int v=1;v<=n;v++) {
            if (!id[v]&&qcnt[v]) {
                pos[++oc]=v;
            }
        }

        memset(tmp,0,1LL*(q+1)*sizeof(int));

        for (int i=1;i<=oc;i++) {
            tmp[qcnt[pos[i]]]++;
        }

        int os=1;

        for (int c=q;c>=1;c--) {
            int x=tmp[c];
            tmp[c]=os;
            os+=x;
        }

        for (int i=1;i<=oc;i++) {
            int v=pos[i];
            ord[tmp[qcnt[v]]++]=v;
        }

        dused=sused=0;

        for (int ii=1;ii<=oc;ii++) {
            int v=ord[ii];
            int tc=0;

            for (int p=beg[v];p<beg[v+1];p++) {
                int u=src[p];

                for (
                    int z=hb[u];
                    z<hb[u+1];
                    z++
                ) {
                    int h=hl[z];

                    if (!ccnt[h]) {
                        tmp[tc++]=h;
                    }

                    ccnt[h]++;
                }
            }

            if (!tc) {
                typ[v]=0;
            } else if (
                tc>H/8&&
                dused+W<=DN_CAP
            ) {
                typ[v]=2;
                off[v]=dused;

                unsigned char *a=
                    dpool+dused;

                memset(a,0,W);

                for (int i=0;i<tc;i++) {
                    int h=tmp[i];
                    a[h]=ccnt[h];
                }

                dused+=W;
            } else if (
                sused+tc<=SP_CAP
            ) {
                typ[v]=1;
                off[v]=sused;
                len[v]=tc;

                for (int i=0;i<tc;i++) {
                    int h=tmp[i];

                    spool[sused++]=
                        ((uint32_t)h<<8)|
                        ccnt[h];
                }
            } else {
                typ[v]=3;
            }

            for (int i=0;i<tc;i++) {
                ccnt[tmp[i]]=0;
            }
        }

        long long qh=0;

        for (int h=1;h<=H;h++) {
            qh+=qcnt[hv[h]];
        }

        C=0;

        for (int ii=1;ii<=oc&&C<CMAX;ii++) {
            int v=ord[ii];

            if (
                typ[v]==2&&
                1LL*qcnt[v]*W>=2*qh
            ) {
                cv[++C]=v;
                cid[v]=C;
            }
        }

        if (C) {
            CW=((C+1+31)>>5)<<5;

            if (!CW) {
                CW=32;
            }

            cdot=alloc64<int>(
                CW,
                true
            );

            ctran=alloc64<unsigned char>(
                1LL*(H+1)*CW,
                true
            );

            for (int c=1;c<=C;c++) {
                int v=cv[c];
                unsigned char *a=
                    dpool+off[v];

                int s=0;

                for (int h=1;h<=H;h++) {
                    int x=a[h];

                    s+=x;
                    ctran[1LL*h*CW+c]=(unsigned char)x;
                }

                cdot[c]=s;
            }
        }

        E=m;
        P=0;

        for (int u=1;u<=n;u++) {
            P+=
                1LL*
                outd[u]*
                (outd[u]-1)/2;
        }
    }

    void solve() {
        n=io.read();
        m=io.read();

        for (int i=1;i<=m;i++) {
            eu[i]=io.read();
            ev[i]=io.read();

            ind[ev[i]]++;
            outd[eu[i]]++;

            uint64_t key=
                (1ULL*eu[i]<<20)|
                (unsigned int)ev[i];

            se[i]=(key<<20)|i;
        }

        radix_sort(se,m);

        obeg[1]=1;

        for (int u=1;u<=n;u++) {
            obeg[u+1]=
                obeg[u]+outd[u];
        }

        beg[1]=1;

        for (int v=1;v<=n;v++) {
            beg[v+1]=
                beg[v]+ind[v];

            pos[v]=beg[v];
        }

        for (int i=1;i<=m;i++) {
            src[pos[ev[i]]++]=eu[i];
        }

        q=io.read();
        int R=0;

        for (int i=1;i<=q;i++) {
            int t=io.read();
            int u=io.read();
            int op=t-1;

            if (!(op&1)) {
                int v=io.read();

                uint64_t key=
                    (1ULL*u<<20)|
                    (unsigned int)v;

                sq[++R]=(key<<20)|i;
                qop[i]=(uint32_t)op;
            } else {
                qcnt[u]++;
                qop[i]=((uint32_t)u<<2)|op;
            }
        }

        if (R) {
            radix_sort(sq,R);

            int p=1;

            for (int j=1;j<=R;j++) {
                uint64_t key=sq[j]>>20;

                for (;(se[p]>>20)<key;p++) {}

                int qi=sq[j]&((1<<20)-1);
                int e=se[p]&((1<<20)-1);
                qop[qi]=((uint32_t)e<<2)|(qop[qi]&3);
            }
        }

        build();

        for (int i=1;i<=q;i++) {
            uint32_t x=qop[i];
            int op=x&3;
            int z=x>>2;

            if (op&1) {
                all_set(
                    z,
                    op>>1
                );
            } else {
                single_set(
                    z,
                    op>>1
                );
            }

            io.yesno(
                E==n&&P==0
            );
        }

        io.flush();
    }
}

signed main() {
    TANGYIXIAO::solve();
    return 0;
}