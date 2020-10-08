#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    ll sum = (1ll * n * (n+1)) / 2;
    if(sum&1){
        puts("NO");
    }
    else{
        vector<int> s1, s2;
        int i;
        sum /= 2ll;
        for(i = n; i > 0; i--){
            if(sum >= i){
                sum -= i;
                s1.push_back(i);
            }
            else{
                s2.push_back(i);
            }
        }
        printf("YES\n%d\n", s1.size());
        for(auto x: s1) printf("%d ", x);
        printf("\n%d\n", s2.size());
        for(auto x: s2) printf("%d ", x);
    }
    return 0;
}
