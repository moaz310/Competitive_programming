#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, sq;
    while(scanf("%lld", &n), n){
        sq = sqrt(n);
        puts(1ll*sq*sq == n ? "yes" : "no");
    }
    return 0;
}
