/*
    Extended Euclidean Algorithm 
    Calcula el GCD entre A y B, devuelve x y y (Ax+By=GCD) 
    O(log(min(A,B))) 
    O(1) memoria

    Extended_Euclid E;
    int x,y;
    int gcd=E.GCD(A,B,x,y);
*/

struct Extended_Euclid
{
    long long GCD(long long a,long long b,long long& x,long long& y){
        if(!b){
            x=1,y=0;
            return a;
        }
        long long x1,y1,g=GCD(b,a%b,x1,y1);
        x=y1,y=x1-a/b*y1;
        return g;
    }
};