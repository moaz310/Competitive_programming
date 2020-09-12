#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
unordered_map<string, int> hsh;
const int MAX = 1e5+5;
char s[20], s2[20];

struct DSU{
    int id[MAX], sz[MAX];

    DSU(){
        for(int i = 0; i < MAX; i++){
            id[i] = i, sz[i] = 1;
        }
    }

    int root(int i){
        while(i != id[i]){
            i = id[i] = id[id[i]];
        }
        return i;
    }

    void unite(int a, int b){
        a = root(a), b = root(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        if(sz[a] == sz[b]) ++sz[a];
        id[b] = a;
    }
};

int main(){
    int n, q, t;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        hsh[s] = i;
    }
    DSU d;
    while(q--){
        scanf("%d %s %s", &t, s, s2);
        if(t == 1){
            d.unite(hsh[s], hsh[s2]);
        }
        else{
            puts(d.root(hsh[s]) == d.root(hsh[s2]) ? "yes" : "no");
        }
    }
    return 0;
}
