#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
vi arr;
int main(){
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < 2*n; i++){
        scanf("%d", &x);
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    int mx = 0, mn = 2e9 + 9;
    for(int i = 0; i < n; i++){
        mx = max(mx, arr[i]+arr[2*n - i - 1]);
        mn = min(mn, arr[i]+arr[2*n - i - 1]);
    }
    printf("%d", mx-mn);
    return 0;
}
