#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m;
int bag[102];
int memo[102][50005];

int dp(int idx, int diff){
    if(idx == m){
        return diff;
    }
    int &res = memo[idx][diff];
    if(res != 1e6){
        return res;
    }
    return res = min(res, min(dp(idx+1, abs(bag[idx]-diff)), dp(idx+1, abs(bag[idx]+diff))));
}


int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        for(int i = 0; i < 102; i++){
            for(int j = 0; j < 50005; j++){
                memo[i][j] = 1e6;
            }
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d", &bag[i]);
        }
        printf("%d\n", dp(0, 0));
    }
    return 0;
}
