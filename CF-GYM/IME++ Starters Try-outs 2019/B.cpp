#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int MAX = 1e3 + 3;
char a[MAX], b[MAX];
int memo[MAX][MAX];
int sz_a, sz_b;

int dp(int i, int j){
    if(i == sz_a || j == sz_b){
        return 0;
    }
    int &res = memo[i][j];
    if(res != -1){
        return res;
    }
    res = max(res, max(dp(i+1, j), dp(i, j+1)));
    if(a[i] == b[j]){
        res = max(res, dp(i+1, j+1) + 1);
    }
    return res;
}
int main(){
    memset(memo, -1, sizeof memo);
    scanf("%s %s", a, b);
    sz_a = strlen(a);
    sz_b = strlen(b);
    printf("%d", dp(0, 0));
    return 0;
}
