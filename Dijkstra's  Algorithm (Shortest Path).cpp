/*
    Dijkstra's  Algorithm (Shortest Path) 
    En un grafo ponderado de N nodos y M aristas
    Dado un nodo A computa:
    dist-la distancia desde A hasta el resto de nodos
    dad-el padre de cada nodo en el shortest path desde A hasta el, dad[A]=-1
    Observaciones: si A y B no estan conectados el path devuelve solo el nodo B
    O((N+M)*log(N)) N nodos y M aristas 
    O(N+M) memoria

    Dijkstra D(N,grafo);
    D.dijkstra(A);
    int distB=D.dist[B];
    vector <int> vec=D.path(B);
*/

struct Dijkstra
{
    int n;
    vector <vector <pair<int,long long>>> grafo;
    vector <long long> dist,dad;
    
    Dijkstra(int _n,vector <vector <pair<int,long long>>> _grafo){
        n=_n;
        grafo=_grafo;
    }

    void dijkstra(int node){
        priority_queue <par,vector <pair<int,long long>>,greater<pair<int,long long>>> cola;
        dist.resize(n+1,LONG_LONG_MAX);
        dad.resize(n+1,-1);
        vector <bool> vis(n+1,false);
        dist[node]=0;
        cola.push({0,node});
        while(!cola.empty()){
            int now=cola.top().s;
            cola.pop();
            if(vis[now]) continue;
            vis[now]=true;
            for(auto i:grafo[now]){
                if(dist[i.f]>dist[now]+i.s){
                    dist[i.f]=dist[now]+i.s;
                    cola.push({dist[i.f],i.f});
                    dad[i.f]=now;
                }
            }
        }
    }

    vector <int> path(int end){
        vector <int> vec;
        vec.push_back(end);
        while(dad[vec.back()]!=-1) vec.push_back(dad[vec.back()]);
        reverse(vec.begin(),vec.end());
        return vec;
    }
};