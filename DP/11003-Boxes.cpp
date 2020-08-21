#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int boxes[2000][2];
int memo[2000][6004];
int dp(int idx, int load){
    if(idx >= n){
        return 0;
    }
    int &res = memo[idx][load];
    if(res != -1){
        return res;
    }
    res = max(res, dp(idx+1, load));
    if(load >= boxes[idx][0]){
        res = max(res, dp(idx+1, min(boxes[idx][1], load-boxes[idx][0])) + 1);
    }
    return res;
}

int main(){
    while(scanf("%d", &n) == 1 && n){
        memset(memo, -1, sizeof memo);
        for(int i = 0; i < n; i++){
            scanf("%d %d", &boxes[i][0], &boxes[i][1]);
        }
        printf("%d\n", dp(0, 6003));
    }
    return 0;
}
