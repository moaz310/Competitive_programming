#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int MAX = 3e3 + 3;
vector<vector<int> > adj(MAX);
bool vis[MAX];

void dfs(int node){
    vis[node] = 1;
    for(auto ch: adj[node]){
        if(!vis[ch]){
            dfs(ch);
        }
    }
}

int bfs(int src){
    memset(vis, 0, sizeof vis);
    vis[src] = 1;
    queue<int> q;
    q.push(src);
    int lvl = 0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            src = q.front();
            q.pop();
            for(auto ch: adj[src]){
                if(!vis[ch]){
                    vis[ch] = 1;
                    q.push(ch);
                }
            }
        }
        lvl++;
    }
    return lvl-1;
}

int main(){
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }
    if(cnt > 1){
        printf("=[");
    }
    else{
        int res = 0;
        for(int i = 1; i <= n; i++){
            res = max(res, bfs(i));
        }
        printf("=] %d", res);
    }
    return 0;
}
