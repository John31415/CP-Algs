/*
    Euler's Totient Function 
    Calcula el Phi de los numeros entre 0 y N
    O(NlogN)
    O(N) memoria

    Euler_Phi E(N);
    vector <int> vec=E.phi;
*/

struct Euler_Phi
{
    vector <int> phi;
    
    Euler_Phi(int n){
        phi.resize(n+1);
        phi[0]=0,phi[1]=1;
        for(int i=2;i<=n;i++) phi[i]=i-1;
        for(int i=2;i<=n;i++){
            for(int j=i+i;j<=n;j+=i){
                phi[j]-=phi[i];
            }
        }
    }
};
