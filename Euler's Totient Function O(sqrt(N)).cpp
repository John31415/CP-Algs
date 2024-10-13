/*
    Euler's Totient Function 
    Calcula el Phi de N
    O(sqrt(N))
    O(1) memoria

    Euler_Phi E;
    int phi=E.Phi(N);
*/

struct Euler_Phi
{
    long long Phi(long long n){
        long long res=n;
        for(long long i=2;i*i<=n;i++){
            if(n%i) continue;
            res-=res/i;
            while(n%i==0) n/=i;
        }
        if(n>1) res-=res/n;
        return res;
    }
};
