#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1200;
bool prime[MAX];
vector<int> p;
void seive(int n = MAX){
    memset(prime, 1, sizeof prime);
    int sq = sqrt(n);
    prime[0] = prime[1] = 0;
    for(int i = 0; i <= sq; i++){
        if(prime[i]){
            for(ll j = i*i; j < n; j+=i){
                prime[j] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(prime[i]){
            p.push_back(i);
        }
    }
}

int n, k;
int memo[MAX][MAX][20];
int dp(int idx = 0, int sum = 0, int len = 0){
    if(idx > p.size() || len > k || sum > n){
        return 0;
    }
    if(sum == n && len == k){
        return 1;
    }
    int &res = memo[idx][sum][len];
    if(res != -1){
        return res;
    }
    return res = dp(idx+1, sum + p[idx], len+1) + dp(idx+1, sum, len);
}
int main(){
    seive();
    while(scanf("%d %d", &n, &k) == 2 && n){
        memset(memo, -1, sizeof memo);
        printf("%d\n", dp());
    }
    return 0;
}
