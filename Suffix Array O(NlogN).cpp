/*
    Suffix Array
    Devuelve un arreglo con las posiciones de los sufijos ordenados
    N = STRING.size()
    O(NlogN)
    O(N) memoria

    Suffix_Array S(STRING); 
    vector <int> vec=S.suffix_array;
*/

struct Suffix_Array
{
    vector <int> suffix_array,c;
    
    Suffix_Array(string cad){
        cad+='$';
        int n=cad.size();
        suffix_array.resize(n),c.resize(n);
        {
            vector <pair<char,int>> a(n);
            for(int i=0;i<n;i++) a[i]={cad[i],i};
            sort(a.begin(),a.end());
            for(int i=0;i<n;i++) suffix_array[i]=a[i].s;
            c[suffix_array[0]]=0;
            for(int i=1;i<n;i++){
                if(a[i].f==a[i-1].f) c[suffix_array[i]]=c[suffix_array[i-1]];
                else c[suffix_array[i]]=c[suffix_array[i-1]]+1;
            }
        }
        int k=0;
        while((1<<k)<n){
            vector <pair<par,int>> a(n);
            for(int i=0;i<n;i++) a[i]={{c[i],c[(i+(1<<k))%n]},i};
            sort(a.begin(),a.end());
            for(int i=0;i<n;i++) suffix_array[i]=a[i].s;
            c[suffix_array[0]]=0;
            for(int i=1;i<n;i++){
                if(a[i].f==a[i-1].f) c[suffix_array[i]]=c[suffix_array[i-1]];
                else c[suffix_array[i]]=c[suffix_array[i-1]]+1;
            }
            k++;
        }
    }
};