#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5;
int actv[MAX][3];
int memo[MAX][3];
int n;

int dp(int idx, int lst){
    if(idx >= n){
        return 0;
    }
    int& res = memo[idx][lst];
    if(lst != -1 && res != 0){
        return res;
    }
    int mx = 0;
    switch (lst){
        case -1:
            mx = max(dp(idx+1, 2) + actv[idx][2], max(dp(idx+1, 0) + actv[idx][0], dp(idx+1, 1) + actv[idx][1]));
        break;
        case 0:
            mx = max(dp(idx+1, 1) + actv[idx][1], dp(idx+1, 2) + actv[idx][2]);
        break;
        case 1:
            mx = max(dp(idx+1, 0) + actv[idx][0], dp(idx+1, 2) + actv[idx][2]);
        break;
        case 2:
            mx = max(dp(idx+1, 1) + actv[idx][1], dp(idx+1, 0) + actv[idx][0]);
        break;
    }
    return res = max(res, mx);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &actv[i][0], &actv[i][1], &actv[i][2]);
    }
    printf("%d", dp(0, -1));
    return 0;
}

