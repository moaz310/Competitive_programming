#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n, x;
    scanf("%d", &n);
    ll missed = (1ll*n*(n+1)) / 2;
    for(int i = 0; i < n-1; i++){
        scanf("%d", &x);
        missed -= x;
    }
    printf("%d", missed);
    return 0;
}
