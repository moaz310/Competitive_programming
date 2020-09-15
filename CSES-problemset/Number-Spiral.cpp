#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t, y, x, mx;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &y, &x);
        mx = max(y, x);
        ll res = 1ll*mx*mx - mx + 1;
        if(mx&1){
            res += (y == mx ? 1ll*x-mx: 1ll*mx-y);
        }
        else{
            res += (y == mx ? 1ll*mx-x: 1ll*y-mx);
        }
        printf("%lld\n", res);
    }
    return 0;
}
