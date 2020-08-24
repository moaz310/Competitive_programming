#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5;
int height[MAX];
int memo[MAX];
int n, k;

int dp(int idx){
    if(idx >= n){
        return 2e9;
    }
    if(idx == n-1){
        return 0;
    }
    int& res = memo[idx];
    if(res != 2e9){
        return res;
    }
    for(int i = 1; i <= k; i++){
        res = min(res, dp(idx+i) + abs(height[idx] - height[idx+i]));
    }
    return res;
}

int main(){
    for(int i = 0; i < MAX; i++) memo[i] = 2e9;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &height[i]);
    }
    printf("%d", dp(0));
    return 0;
}
