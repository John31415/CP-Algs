/*
    Pascal Triangle 
    Computa el triangulo de pascal desde la fila 0 hasta la N
    O(N^2)
    O(N^2) memoria

    Pascal_Triangle P(N,MOD);
*/

struct Pascal_Triangle
{
    vector <vector <long long>> pascal;

    Pascal_Triangle(int n,int mod){
        pascal.resize(n+1,vector <long long>(n+1));
        pascal[0][0]=1;
        for(int i=1;i<=n;i++){
            pascal[i][0]=pascal[i][i]=1;
            for(int j=1;j<i;j++){
                pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
            }
        }
    }
};