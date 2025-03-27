/*
    Gauss-Jordan
    Dado un "vector < bitset >" como matriz(nxm), resuelve el sistema en ans mod 2
    O(n*m*min(n,m)/32)
    O(nm/32) memoria

    Nota: Fijar sz bitset en const N

    G.gauss(k,n,a,ans);
*/

const int N; // set bitset size
struct Gauss
{
    int gauss(int n,int m,vector<bitset<N>> a,bitset<N>& ans){
        int rank=0;
        vector<int> where(m,-1);
        for(int col=0,row=0;col<m && row<n;col++){
            for(int i=row;i<n;++i)
                if(a[i][col]){
                    swap(a[i],a[row]);
                    break;
                }
            if(!a[row][col]) continue;
            where[col]=row;
            for(int i=0;i<n;++i)
                if(i!=row && a[i][col]) a[i]^=a[row];
            row++,rank++;
        }
        ans.reset();
        for(int i=m-1;i>=0;i--){
            if(where[i]==-1) ans[i]=true;
            else{
                int k=where[i];
                for(int j=i+1;j<m;j++) if(a[k][j]) ans[i]=ans[i]^ans[j];
                ans[i]=ans[i]^a[k][m];
            }
        }
        for(int i=rank;i<n;i++) if(a[i][m]) return -1; // no solution
        int free_var=0;
        for(int i=0;i<m;i++) if(where[i]==-1) free_var++;
        return free_var; // has solution
    }
} G;