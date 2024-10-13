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
    vector <vector <int>> bfd;
    vector <int> suffix_array;

    Suffix_Array(string cad){
        cad+='$';
        int length=cad.size(),lg=log2(length);
        if((1<<lg)<length) lg++;
        bfd.resize(2,vector <int>(length));
        map <char,int> m; 
        for(auto i:cad) m[i]=true;
        int id=0;
        for(auto &i:m) i.s=id++;
        for(int i=0;i<length;i++) bfd[0][i]=m[cad[i]];
        for(int i=1;i<=lg;i++){
            vector <vector <int>> radix1(length),radix2(length);
            for(int j=0;j<length;j++) radix1[bfd[(i+1)%2][(j+(1<<(i-1)))%length]].push_back(j);
            for(int j=0;j<length && radix1[j].size();j++){
                for(auto k:radix1[j]){
                    radix2[bfd[(i+1)%2][k]].push_back(k);
                }
            }
            id=0;
            for(int j=0;j<length && radix2[j].size();j++){
                bfd[i%2][radix2[j][0]]=id++;
                for(int k=1;k<radix2[j].size();k++){
                    if(bfd[(i+1)%2][(radix2[j][k]+(1<<(i-1)))%length]!=bfd[(i+1)%2][(radix2[j][k-1]+(1<<(i-1)))%length]){
                        bfd[i%2][radix2[j][k]]=id++;
                    }else bfd[i%2][radix2[j][k]]=id-1;
                }
            }
        }
        suffix_array.resize(length);
        for(int i=0;i<length;i++) suffix_array[bfd[lg%2][i]]=i;
    }
};