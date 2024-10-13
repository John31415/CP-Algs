/*
    Modular Inverse Array
    Recibe un array de N elementos y devuelve otro con el inverso modular de los elementos del array recibido
    mod debe ser primo
    O(N)
    O(N) memoria

    Mod_Inv_Array M;
    vector <long long> asd=M.Inv_Array(VEC,MOD);
*/

struct Mod_Inv_Array
{
    long long qpow(long long a,int b){
        if(!b) return 1;
        long long aux=1;
        while(b){
            if(b&1) aux=aux*a%mod;
            a=a*a%mod,b>>=1;
        }
        return aux;
    }

    vector <long long> Inv_Array(vector <long long> vec,long long mod){
        int n=vec.size();
        vector <long long> pref,suff,inv;
        pref.resize(n+1);
        suff.resize(n+2);
        inv.resize(n);
        pref[0]=1;
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]*vec[i-1]%mod;
        }
        long long prod_inv=qpow(pref[n],mod-2);
        suff[n+1]=1;
        for(int i=n;i>0;i--){
            suff[i]=suff[i+1]*vec[i-1]%mod;
            inv[i-1]=pref[i-1]*suff[i+1]%mod*prod_inv%mod;
        }
        return inv;
    }
};