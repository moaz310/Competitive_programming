#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int items[200][2];
ll memo[200][200000];
int n;

ll dp(int idx, int cap){
    if(idx >= n || cap < 0){
        return 0;
    }
    ll &res = memo[idx][cap];
    if(res != -1){
        return res;
    }
    if(cap - items[idx][0] >= 0){
        res = max(res, dp(idx+1, cap-items[idx][0])+items[idx][1]);
    }
    res = max(res, dp(idx+1, cap));
    return res;
}

int main(){
    memset(memo, -1, sizeof memo);
    int w;
    scanf("%d %d", &n, &w);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &items[i][0], &items[i][1]);
    }
    printf("%lld", dp(0, w));
    return 0;
}
