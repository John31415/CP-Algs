/*
    Number-Most-Divisors
    Devuelve el numero mas pequeño con mas divisores hasta N
    
    NumberMostDivisors N;
    cout<<N.f(10)<<" "<<N.h();
*/

struct NumberMostDivisors
{
    int arr[10]={2,3,5,7,11,13,17,19,23,29},aux[30],q,m=-1<<30;
    long long n,r,s=1;
    unordered_map <long long,bool> mapa;

    long long f(int n_){
        n=n_,g(0);
        return r;
    }

    void g(int it){
        if(s>n) return;
        for(int i=it;i<10;i++){
            if(i>0 && aux[arr[i]]>=aux[arr[i-1]]) continue;
            s*=arr[i],aux[arr[i]]++,g(i),s/=arr[i],aux[arr[i]]--;
            if(!mapa.count(s)){
                mapa[s]=true,q=1;
                for(int j=0;j<=i;j++) q*=(aux[arr[j]]+1);
                if(q==m) r=min(r,s);
                else if(q>m) m=q,r=s;
            }
        }
    }

    long long h(){//opcional
        int c=0;
        for(int i=1;i*i<=r;i++){
            if(r%i==0){
                c+=2;
                if(i*i==r) c--;
            }
        }
        return c;
    }
};