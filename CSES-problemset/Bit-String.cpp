#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int main() {
    int n, res = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        res = res * 2ll;
        res %= MOD;
    }
    printf("%d", res);
    return 0;
}
