/*
    Euler's Totient Function 
    Calcula el Phi de los numeros entre 0 y N
    O(NloglogN)
    O(N) memoria

    Euler_Phi E(N);
    vector <long long> vec=E.phi;
*/

struct Euler_Phi
{
    vector <int> phi;
    
    Euler_Phi(int n){
        phi.resize(n+1);
        for(int i=0;i<=n;i++) phi[i]=i;
        for(int i=2;i<=n;i++){
            if(phi[i]==i){
                for(int j=i;j<=n;j+=i){
                    phi[j]-=phi[j]/i;
                }
            }
        }
    }
};