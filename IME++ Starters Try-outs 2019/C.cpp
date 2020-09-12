#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
vi arr;
int n, x, d, val;

int sol(int mask){
    int idx = 0, mn = 1e9 + 9, mx = -1;
    ll sum = 0;
    while(mask){
        if(mask&1){
            sum += 1ll*arr[idx];
            mn = min(mn, arr[idx]);
            mx = max(mx, arr[idx]);
        }
        idx++;
        mask >>= 1;
    }
    return (sum >= x && (mx - mn) <= d);
}

int main(){
    scanf("%d %d %d", &n, &x, &d);
    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        arr.push_back(val);
    }
    int res = 0;
    for(int i = 1; i < (1 << n); i++){
        res += sol(i);
    }
    printf("%d", res);
    return 0;
}
