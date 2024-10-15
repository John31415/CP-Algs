
struct Fenwick_Tree{
    int n;
    vector <long long> abi;

    Fenwick_Tree(int _n){
        n=_n;
        abi.assign(2*n,0);
    }

    void add(int k){
        while(k<=n) abi[k]++,k+=k&-k;
    }

    void add(int k,long long val){
        while(k<=n) abi[k]+=val,k+=k&-k;
    }

    long long query(int k){
        long long s=0;
        while(k) s+=abi[k],k-=k&-k;
        return s;
    }

    long long query(int a,int b){
        return query(b)-query(a-1);
    }
};