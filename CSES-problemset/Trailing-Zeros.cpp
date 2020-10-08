#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pow5[] = {5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 0; i < 12; i++){
        cnt += n/pow5[i];
    }
    printf("%d", cnt);
    return 0;
}
