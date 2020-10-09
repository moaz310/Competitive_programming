#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[30];
int main(){
    int n;
    ll sum = 0, res = 2e9;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += 1ll*arr[i];
    }
    for(int i = 0; i < (1<<n); i++){
        int mask = i, j = 0;
        ll rem = 0;
        while(mask){
            if(mask&1){
                rem += 1ll*arr[j];
                sum -= 1ll*arr[j];
            }
            j++;
            mask >>= 1;
        }
        res = min(res, abs(sum-rem));
        sum += rem;
    }
    printf("%d", res);
    return 0;
}
