/*
    Euclidean Algorithm 
    Calcula GCD
    O(log(min(A,B))) A y B numeros a los cuales se les halla el GCD
    O(1) memoria

    Euclid_GCD E;
    int gcd=E.GCD(A,B);
*/

struct Euclid_GCD
{
    long long GCD(long long a,long long b){
        return b?GCD(b,a%b):a;
    }
};