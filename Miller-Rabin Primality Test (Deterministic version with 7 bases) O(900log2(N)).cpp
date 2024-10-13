/*
    Miller Rabin 
    Verifica si un N dado es Primo
    O(900log2(N))
    O(1) memoria

    Miller_Rabin R;
    R.Is_Prime(N);
*/

struct Miller_Rabin
{
    long long mul(long long a,long long b,long long mod){
        long long aux=0;
        while(b){
            if(b&1) aux=(aux+a)%mod;
            a=(a<<1)%mod,b>>=1;
        }
        return aux;
    }

    long long qpow(long long a,long long b,long long mod){
        if(!b) return 1;
        long long aux=1;
        while(b){
            if(b&1) aux=mul(aux,a,mod);
            a=mul(a,a,mod),b>>=1;
        }
        return aux;
    }

    bool Is_Prime(long long n){
        if(n<2 || (n>2 && n%2==0)) return false;
        for(auto i:{2,3,5,13,19,73,193,407521,299210837}) if(n==i) return true;
        long long s=__builtin_ctz(n-1),d=(n-1)>>s;
        for(auto a:{2,325,9375,28178,450775,9780504,1795265022}){
            long long x=qpow(a,d,n);
            bool band=(x==1)|(x==n-1);
            for(long long j=1;j<s && !band;j++) x=mul(x,x,n),band=(x==n-1);
            if(band==0) return 0;
        }
        return true;
    }
};