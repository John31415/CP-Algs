/*
    Kosaraju's Algorithm (Strongly Connected Components) 
    En un grafo dirigido los nodos A y B esta fuertemente conectados si existe una ruta de A->B y B->A.
    El algoritmo genera un vector scc, scc[node] = id de la componente a la que pertenece el nodo, (id >= 1).
    O(N+M), N nodos y M aristas 
    O(N+M) memoria

    Kosaraju K(N,grafo);
    K.SCC(N);
    vec=K.scc;
*/

struct Kosaraju
{
    vector <int> scc,vec;
    vector <vector <int>> out,in;
    vector <bool> vis;

    Kosaraju(int n, vector <vector <int>> _out){
        scc.resize(n+1);
        vis.resize(n+1);
        out=_out;
        in.resize(n+1);
        for(int i=1;i<=n;i++){
            for(auto j:out[i]){
                in[j].push_back(i);
            }
        }
    }

    void dfs1(int node){
        vis[node]=true;
        for(auto i:out[node]){
            if(vis[i]) continue;
            dfs1(i);
        }
        vec.push_back(node);
    }

    void dfs2(int node,int dad){
        vis[node]=true;
        scc[node]=dad;
        for(auto i:in[node]){
            if(vis[i]) continue;
            dfs2(i,dad);
        }
    }

    void SCC(int n){
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs1(i);
            }
        }
        reverse(vec.begin(),vec.end());
        fill(vis.begin(),vis.end(),false);
        int id=1;
        for(auto i:vec){
            if(!vis[i]){
                dfs2(i,id++);
            }
        }
    } 
};