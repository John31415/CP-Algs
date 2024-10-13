/*
    Disjoin Set - Union-Find
    O(α(N)) muy rapido, N elementos
    O(N) memoria
    
    DSU dsu(N);
    dsu.Union(a,b);
    bool band=dsu.Find(a);
*/

struct DSU{
    vector <int> dad,count;

    DSU(int n){
        dad.resize(n+1);
        count.resize(n+1);
        for(int i=0;i<=n;i++){
            dad[i]=i;
            count[i]=1;
        }
    }

    int Find(int x){
        return x==dad[x]?x:dad[x]=Find(dad[x]);
    }

    void Union(int a,int b){
        a=Find(a),b=Find(b);
        if(a>b) swap(a,b);
        count[a]+=count[b];
        dad[b]=a;
    }
};
