#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5;
int height[MAX];
int memo[MAX];
int n;

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
    int mn = min(dp(idx+1) + abs(height[idx] - height[idx+1]), dp(idx+2) + abs(height[idx] - height[idx+2]));
    return res = min(res, mn);
}

int main(){
    for(int i = 0; i < MAX; i++) memo[i] = 2e9;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &height[i]);
    }
    printf("%d", dp(0));
    return 0;
}
