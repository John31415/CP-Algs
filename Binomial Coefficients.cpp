/*
    Binomial Coefficients
    Computa los primeros N factorials y sus inversos para calcular comb(N,k,mod) de manera eficiente
    mod debe ser un numero primo
    O(N) precomputo
    O(1) query
    O(N) memoria

    Binomial_Coefficients B(N,MOD);
    int solve=B.Comb(n,k);
*/

struct Binomial_Coefficients
{
    vector <long long> fact,ifact;

    long long qpow(int a,int b){
        if(!b) return 1;
        long long aux=1;
        while(b){
            if(b&1) aux=aux*a%mod;
            a=a*a%mod,b>>=1;
        }
        return aux;
    }

    Binomial_Coefficients(int n,long long mod){
        fact.resize(n+1);
        ifact.resize(n+1);
        fact[0]=1;
        for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
        ifact[n]=qpow(fact[n],mod-2);
        for(int i=n-1;i>=0;i--) ifact[i]=ifact[i+1]*(i+1)%mod;
    }

    long long Comb(int n,int k, long long mod){
        return fact[n]*ifact[k]%mod*ifact[n-k]%mod;
    }
};